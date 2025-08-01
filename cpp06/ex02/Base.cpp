/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:41:31 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/02 00:26:01 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {}

Base*	generate(void)
{
	int	n = std::rand() % 3;

	std::cout << "[Generate]: ";
	if (n == 0)
	{
		std::cout << "A" << std::endl;
		Base*	res = new A();
		return (res);
	}
	else if (n == 1)
	{
		std::cout << "B" << std::endl;
		Base*	res = new B();
		return (res);
	}
	else
	{
		std::cout << "C" << std::endl;
		Base*	res = new C();
		return (res);
	}
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

	std::cout << "Actual type of the object pointed to by p: ";
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cout << "unkwon" << std::endl;

}

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

	std::cout << "unkwon" << std::endl;
}
