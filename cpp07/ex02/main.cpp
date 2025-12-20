#include <iostream>
#include "Array.hpp"

int	main(void)
{
	std::cout << "[DEFAULT CONSTRUCTOR]" << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	std::cout << "\n[CONSTRUCTOR WITH PARAMETER]" << std::endl;
	Array<int> numbers(5);
	std::cout << "Size: " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	std::cout << "\n[COPY CONSTRUCTOR]" << std::endl;
	Array<int> copy(numbers);
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;

	std::cout << "\n[COPY ASSIGNMENT OPERATOR]" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 888;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;

	std::cout << "\n[OUT OF BOUNDS TEST]" << std::endl;
	try
	{
		std::cout << numbers[42] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "\n[DIFFERENT TYPE TEST]" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "world";
	strings[2] = "!";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
	return (0);
}

// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;
// 	return 0;
// }