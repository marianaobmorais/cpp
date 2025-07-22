/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:56:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 15:32:21 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL)); //randomize robotomy at runtime

	Bureaucrat	bob("Bob", 25);
	Intern		someRandomIntern;
	std::cout << "\n-----------------Shrubbery Creation Form-----------------"<< std::endl;
	try
	{
		AForm		*scf;

		std::cout << "Intern tries to create Shrubbery Creation Form" << std::endl;
		scf = someRandomIntern.makeForm("invalid name", "home");
		std::cout << *scf;
		std::cout << bob;
		bob.signForm(*scf);
		std::cout << *scf;
		bob.executeForm(*scf);
		
		delete scf;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	
	std::cout << "\n-----------------Robotomy Request Form-----------------"<< std::endl;
	try
	{
		AForm		*rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		std::cout << bob;
		bob.signForm(*rrf);
		std::cout << *rrf;
		bob.executeForm(*rrf);
		
		delete rrf;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n-----------------Presidential Pardon Form-----------------"<< std::endl;
	try
	{
		AForm		*ppf;

		ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
		std::cout << *ppf;
		bob.executeForm(*ppf);
		bob.signForm(*ppf);
		std::cout << *ppf;
		bob.executeForm(*ppf);
		
		Bureaucrat	billy("Billy", 2);
		
		std::cout << billy;
		billy.signForm(*ppf);
		std::cout << *ppf;
		billy.executeForm(*ppf);

		delete ppf;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception Bob error: " << e.what() << std::endl;
	}

	return (0);
}
