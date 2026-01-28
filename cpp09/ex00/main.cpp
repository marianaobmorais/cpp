#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw std::logic_error("USAGE: btc <input>");

		std::string		db_exchange_rates("./data.csv");
		std::ifstream	rates_infile(db_exchange_rates);
		if (!rates_infile.good())
			throw std::logic_error("Error: could not open file.");

		BitcoinExchange btc;

		btc.load_exchange_rates(rates_infile);

		std::string		db_values(argv[1]);
		std::ifstream	values_infile(db_values);
		if (!values_infile.good())
			throw std::logic_error("Error: could not open file.");

		btc.process_values(values_infile);
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}