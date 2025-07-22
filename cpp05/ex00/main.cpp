/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:56:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 14:35:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n------------------Valid bureaucrat-------------------" << std::endl;
	try
	{
		Bureaucrat	a("Arnold", 130);
		std::cout << a;
		std::cout << "After grade increment:\n";
		a.increment();
		std::cout << a;

		std::cout << "After grade decrement:\n";
		a.decrement();
		std::cout << a;
		std::cout << "--Copy constructor--" << std::endl;
		Bureaucrat a2(a);
		std::cout << a2;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------Invalid bureaucrat (grade too low)----------" << std::endl;
	try
	{
		Bureaucrat	b("Bob", 151);
		std::cout << b;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------Invalid bureaucrat (grade too high)----------" << std::endl;
	try
	{
		Bureaucrat c("Carl", 0);
		std::cout << c;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------Copy assignment tests-----------------" << std::endl;
	std::cout << "--Bureaucrats have same name--" << std::endl;
	try
	{
		Bureaucrat	d("Denis", 50);
		Bureaucrat	e("Denis", 100);
		std::cout << "-Before assignment:\n" << d << e;

		d = e;
		std::cout << "-After assignment:\n" << d << e;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() <<std::endl;
	}

	std::cout << "--Bureaucrats have different names-- " << std::endl;
	try
	{
		Bureaucrat	f("Frank", 120);
		Bureaucrat	g("Gordon", 30);
		std::cout << "-Before assignment:\n" << f << g;

		f = g;
		std::cout << "-After assignment:\n" << f << g;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------Increment overflow-------------------" << std::endl;
	try
	{
		Bureaucrat	h("Hannah", 1);
		std::cout << "-Before increment:\n" << h;
		h.increment();
		std::cout << "After increment:\n" << h;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "------------------Decrement overflow-------------------" << std::endl;
	try
	{
		Bureaucrat	i("Igor", 150);
		std::cout << "-Before decrement:\n" << i;
		i.decrement();
		std::cout << "After decrement:\n" << i;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}