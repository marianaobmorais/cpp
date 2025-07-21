/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:56:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 20:14:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 25);
	ShrubberyCreationForm	home("home");
	std::cout << bob;
	std::cout << home;
	bob.signForm(home);
	std::cout << home;
	bob.executeForm(home);

	PresidentialPardonForm pardon("Arthur");
	std::cout << pardon;
	bob.executeForm(pardon);
	bob.signForm(pardon);
	std::cout << pardon;
	bob.executeForm(pardon);

	Bureaucrat	billy("Billy", 2);
	billy.signForm(pardon);
	std::cout << pardon;
	billy.executeForm(pardon);
	
	// std::cout << "-----------------Valid form-----------------"<< std::endl;
	// try
	// {
	// 	Form f("Some Form", 1, 1);
	// 	std::cout << f;
	// 	std::cout << "--Lower bureaucrat grade--"<< std::endl;
	// 	Bureaucrat b("Bob", 4);
	// 	std::cout << b;
	// 	b.signForm(f);
	// 	std::cout << f;
	// 	std::cout << "--Valid bureaucrat grade--"<< std::endl;
	// 	Bureaucrat b2("Beatrice", 1);
	// 	std::cout << b2;
	// 	b2.signForm(f);
	// 	std::cout << f;
	// 	std::cout << "--Invalid sign--"<< std::endl;
	// 	Bureaucrat b3("Bruno", 1);
	// 	std::cout << b3;
	// 	b3.signForm(f);
	// }
	// catch (std::exception const& e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }

	// std::cout << "-----------------Invalid form-----------------"<< std::endl;
	// std::cout << "--Too high grade to sign--"<< std::endl;
	// try
	// {
	// 	Form f2("Invalid form", 0, 150);
	// 	std::cout << f2;
	// }
	// catch (std::exception const& e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// std::cout << "--Too low grade to execute--"<< std::endl;
	// try
	// {
	// 	Form f3("Invalid form", 15, 151);
	// 	std::cout << f3;
	// }
	// catch (std::exception const& e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// return (0);
}