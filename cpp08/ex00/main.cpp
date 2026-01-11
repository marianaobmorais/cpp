#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int	main(void)
{
	std::cout << "[LIST TEST]\n" << std::endl;

	std::list<int>	lst;
	int				v1 = 1;
	int				v2 = 5;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(6);

	try
	{
		std::list<int>::const_iterator it1 = easyfind(lst, v1);
		std::cout << "Value found: " << *it1 << std::endl;
		std::list<int>::const_iterator it2 = easyfind(lst, v2);
		std::cout << "Value found: " << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "\n[VECTOR TEST]\n" << std::endl;

	std::vector<int>	vct;
	int				v3 = 10;
	int				v4 = 50;

	vct.push_back(30);
	vct.push_back(10);
	vct.push_back(20);
	vct.push_back(100);

	try
	{
		std::vector<int>::const_iterator it3 = easyfind(vct, v3);
		std::cout << "Value found: " << *it3 << std::endl;
		std::vector<int>::const_iterator it4 = easyfind(vct, v4);
		std::cout << "Value found: " << *it4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "\n[DEQUE TEST]\n" << std::endl;

	std::deque<int>	dq;
	int				v5 = 100;
	int				v6 = 900;

	dq.push_back(30);
	dq.push_back(100);
	dq.push_back(250);
	dq.push_back(100);

	try
	{
		std::deque<int>::const_iterator it5 = easyfind(dq, v5);
		std::cout << "Value found: " << *it5 << std::endl;
		std::deque<int>::const_iterator it6 = easyfind(dq, v6);
		std::cout << "Value found: " << *it6 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}