#include "RPN.hpp"

int	main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw std::logic_error("Error");

		std::string	args(argv[1]);
		RPN	stack;
		stack.process_elements(args);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}