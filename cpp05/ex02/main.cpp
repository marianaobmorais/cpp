/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:56:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 11:23:56 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int	main(void)
{
	std::srand(std::time(NULL)); //randomize robotomy at runtime

	Bureaucrat	bob("Bob", 25);
	ShrubberyCreationForm	home("home");
	std::cout << "-----------------Shrubbery Creation Form-----------------"<< std::endl;
	try
	{
		std::cout << bob;
		std::cout << home;
		bob.signForm(home);
		std::cout << home;
		bob.executeForm(home);
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception Shrubbery Creation Form: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	PresidentialPardonForm pardon("Arthur");
	std::cout << "-----------------Presidential Pardon Form-----------------"<< std::endl;
	try
	{
		std::cout << pardon;
		bob.executeForm(pardon);
		bob.signForm(pardon);
		std::cout << pardon;
		bob.executeForm(pardon);
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception Bob error: " << e.what() << std::endl;
	}

	Bureaucrat	billy("Billy", 2);
	try
	{
		std::cout << billy;
		billy.signForm(pardon);
		std::cout << pardon;
		billy.executeForm(pardon);
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception Billy error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-----------------Robotomy Request Form-----------------"<< std::endl;
	try
	{
		AForm* formPtr = new RobotomyRequestForm("Marvin");
		std::cout << *formPtr;
		billy.signForm(*formPtr);
		std::cout << *formPtr;
		formPtr->execute(billy);
		
		delete formPtr;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception caught in main: " << e.what() << std::endl;
	}

	return (0);
}
