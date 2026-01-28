#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _exchange_rates(src._exchange_rates) {}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		this->_exchange_rates = rhs._exchange_rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::display_output(std::string date, double value)
{
	std::map<std::string, double>::const_iterator	it;
	std::string										date_used;

	it = this->_exchange_rates.lower_bound(date);
	if (it != this->_exchange_rates.end() && it->first == date)
		date_used = date;
	else
	{
		if (it == this->_exchange_rates.begin())
		{
			std::cout << "Error: no exchange rate available for this date." << std::endl;
			return ;
		}
			--it;
			date_used = it->first;
	}

	std::cout << date_used << " => " << value << " = " << value * it->second << std::endl;
}

double	BitcoinExchange::validate_value(std::string value_str)
{
	char	*endPtr;
	errno	= 0;

	double	value = std::strtod(value_str.c_str(), &endPtr);
	if (errno != 0 || endPtr == value_str.c_str() || *endPtr != '\0')
	{
		std::cout << "Error: invalid number." << std::endl;
		return (-1);
	}
	else if (value_str.find('e') != std::string::npos || value_str.find('E') != std::string::npos)
	{
		std::cout << "Error: invalid number." << std::endl;
		return (-1);
	}
	else if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	else if (value > 1000)
	{
		std::cout << "Error: too large of a number." << std::endl;
		return (-1);
	}
	else
		return (value);
}

double	BitcoinExchange::validate_rate(std::string rate_str)
{
	char	*endPtr;
	errno	= 0;

	double	rate = std::strtod(rate_str.c_str(), &endPtr);
	if (errno != 0 || endPtr == rate_str.c_str() || *endPtr != '\0'|| rate < 0)
		return (-1);

	return (rate);
}

std::string	BitcoinExchange::validate_date(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (std::string());

	for (std::size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (std::string());
	}

	std::size_t	first_dash = 4;
	std::size_t second_dash = 7;
	std::string	year_str = date.substr(0, first_dash);
	std::string	month_str = date.substr(first_dash + 1, second_dash - (first_dash + 1));
	std::string	day_str = date.substr(second_dash + 1);

	int	year = std::atoi(year_str.c_str());
	int	month = std::atoi(month_str.c_str());
	int	day = std::atoi(day_str.c_str());

	if ((year > 2026) || (month < 1 || month > 12))
		return (std::string());

	int	max_day;
	if (month == 2)
	{
		bool	leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		max_day = leap_year ? 29 : 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		max_day = 31;
	else
		max_day = 30;
	if (day < 1 || day > max_day)
		return (std::string());

	return (date);
}

void	BitcoinExchange::load_exchange_rates(std::ifstream &rates_infile)
{
	std::string	line;

	if (!std::getline(rates_infile, line) || line != "date,exchange_rate")
		throw std::logic_error("Error: invalid header in exchange rate database.");
	while (std::getline(rates_infile, line))
	{
		if (line.empty() || line.length() < 12)
			throw std::logic_error("Error: invalid line in exchange rate database.");

		std::size_t	comma_position = line.find(',');
		if (comma_position == std::string::npos || comma_position != line.rfind(','))
			throw std::logic_error("Error: invalid comma placement in exchange rate database.");

		std::string	date_init = line.substr(0, comma_position);
		std::string	date = validate_date(date_init);
		if (date.empty())
			throw std::logic_error("Error: invalid date format in exchange rate database.");

		std::string	rate_str = line.substr(comma_position + 1);
		double	rate = validate_rate(rate_str);
		if (rate < 0)
			throw std::logic_error("Error: invalid rate in exchange rate database.");

		this->_exchange_rates[date] = rate;
	}
	if (this->_exchange_rates.empty())
		throw std::logic_error("Error: invalid exchange rate database.");
}

void	BitcoinExchange::process_values(std::ifstream &values_infile)
{
	std::string	line;

	if (!std::getline(values_infile, line) || line != "date | value")
		throw std::logic_error("Error: invalid header in input database.");
	while (std::getline(values_infile, line))
	{
		if (line.empty())
		{
			std::cout << "Error: bad input => empty line." << std::endl;
			continue ;
		}

		std::size_t	first_space_position = line.find(' ');
		std::string	date_init = line.substr(0, first_space_position);
		std::string	date = validate_date(date_init);
		if (date.empty())
		{
			std::cout << "Error: bad input => " + date_init << std::endl;
			continue ;
		}

		if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		{
			std::cout << "Error: bad input => USAGE: <YYYY-MM-DD> | <value>." << std::endl;
			continue ;
		}

		std::size_t	last_space_position = line.rfind(' ');

		std::string	value_init = line.substr(last_space_position);
		double	value = validate_value(value_init);
		if (value == -1)
			continue ;

		display_output(date, value);
	}
}
