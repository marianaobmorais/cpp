#include "Span.hpp"
#include <iostream>
#include <list>

int	main(void)
{
	try
	{
		std::cout << "[SIMPLE TEST]\n" << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::cout << "\n[OVERFLOW TEST]\n" << std::endl;

		Span sp(3);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
	}
	catch(std::exception const& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << "\n[NOT ENOUGH VALUES TEST]\n" << std::endl;

		Span sp(3);

		sp.addNumber(6);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	try
	{
		std::cout << "\n[STRESS TEST - KNOWN VALUES]\n" << std::endl;

		Span sp(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(i * 2);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	std::srand(std::time(NULL));

	try
	{
		std::cout << "\n[STRESS TEST - VECTOR]\n" << std::endl;

		int const N = 10000;
		std::vector<int> tmp(N);
		std::generate(tmp.begin(), tmp.end(), std::rand);

		Span sp(N);
		sp.addNumber(tmp.begin(), tmp.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
    try
    {
        std::cout << "\n[STRESS TEST - LIST]\n" << std::endl;

        const int N = 10000;
        std::list<int> tmp;
        for (int i = 0; i < N; ++i)
            tmp.push_back(i * 2);

        Span sp(N);
        sp.addNumber(tmp.begin(), tmp.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan()  << std::endl;
    }
    catch(std::exception const& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

	return (0);
}
