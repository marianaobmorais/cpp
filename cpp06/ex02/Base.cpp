/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:41:31 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/04 16:55:50 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/// @brief Constructor for Base object.
Base::~Base(void) {}

/// @brief Randomly generates an instance of one of the classes A, B, or C, and returns it as a Base pointer.
/// @return A pointer to a newly allocated instance of A, B, or C (as Base*).
Base*	generate(void)
{
	int	n = std::rand() % 3;

	std::cout << "[Generate]: ";
	switch (n)
	{
		case 0:
			std::cout << "A" << std::endl;
			return (new A());
		case 1:
			std::cout << "B" << std::endl;
			return (new B());
		case 2:
			std::cout << "C" << std::endl;
			return (new C());
	}
	return (NULL);
}

/// @brief Identifies the dynamic type of the object pointed to by a Base pointer
/// using dynamic_cast.
/// @param p Pointer to a Base object.
void	identify(Base* p)
{
	std::cout << "Actual type of the object pointed to by p: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;

}

/// @brief Identifies the dynamic type of the object referenced by a Base reference
/// using dynamic_cast and exception handling.
/// @param p Reference to a Base object.
/// @note Outputs the actual type to std::cout.
void	identify(Base& p)
{
	std::cout << "Actual type of the object referenced to by p: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception const& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception const& e) {}

	std::cout << "unknown" << std::endl;
}
