#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw std::logic_error("Error");

		PmergeMe sorter;

		for (int i = 1; i < argc; ++i)
			sorter.addNumber(argv[i]);

		sorter.process();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
