#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cerrno>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_exchange_rates;
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange&	operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);

		void		load_exchange_rates(std::ifstream &rates_infile);
		std::string	validate_date(std::string date);
		double		validate_rate(std::string value_str);
		double		validate_value(std::string value);
		void		process_values(std::ifstream &values_infile);
		void		display_output(std::string date, double value);
};

#endif //BITCOIN_EXCHANGE_HPP