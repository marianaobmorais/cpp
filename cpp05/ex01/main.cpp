/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:56:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/24 17:28:01 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "\n-----------------Valid form-----------------"<< std::endl;

	Form f("Some Form", 1, 1);
	std::cout << f;
	std::cout << "--Lower bureaucrat grade--"<< std::endl;
	try
	{
		Bureaucrat b("Bob", 4);
		std::cout << b;
		b.signForm(f);
		std::cout << f;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "--Valid bureaucrat grade--"<< std::endl;
	try
	{
		Bureaucrat b2("Beatrice", 1);
		std::cout << b2;
		b2.signForm(f);
		std::cout << f;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "--Sign already signed form--"<< std::endl;
	try
	{
		Bureaucrat b3("Bruno", 1);
		std::cout << b3;
		b3.signForm(f);
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--Sign a higher grade form--"<< std::endl;
	try
	{
		Form	f1("Tough form", 50, 50);
		Bureaucrat	b4("Benny", 150);
		b4.signForm(f1);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	

	std::cout << "\n-----------------Invalid form creation-----------------"<< std::endl;
	std::cout << "--Too high form grade to sign--"<< std::endl;
	try
	{
		Form f2("Invalid form", 0, 150);
		std::cout << f2;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--Too low form grade to execute--"<< std::endl;
	try
	{
		Form f3("Invalid form", 15, 151);
		std::cout << f3;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}