/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:56:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 09:49:19 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int	main(void)
{
	std::cout << "-----------------Shrubbery Creation Form-----------------"<< std::endl;
	Bureaucrat	bob("Bob", 25);
	ShrubberyCreationForm	home("home");
	std::cout << bob;
	std::cout << home;
	bob.signForm(home);
	std::cout << home;
	bob.executeForm(home);

	std::cout << "-----------------Presidential Pardon Form-----------------"<< std::endl;
	PresidentialPardonForm pardon("Arthur");
	std::cout << pardon;
	bob.executeForm(pardon);
	bob.signForm(pardon);
	std::cout << pardon;
	bob.executeForm(pardon);

	Bureaucrat	billy("Billy", 2);
	std::cout << billy;
	billy.signForm(pardon);
	std::cout << pardon;
	billy.executeForm(pardon);
	
	std::cout << "-----------------Robotomy Request Form-----------------"<< std::endl;
	AForm* formPtr = new RobotomyRequestForm("Marvin");
	std::cout << *formPtr;
	billy.signForm(*formPtr);
	std::cout << *formPtr;
	formPtr->execute(billy);

	delete formPtr;

	return (0);
}