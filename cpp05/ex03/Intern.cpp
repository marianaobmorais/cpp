/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:59:14 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 13:44:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/// @brief Default constructor for Intern.
Intern::Intern(void) {}

/// @brief Copy constructor for Intern (no-op since Intern has no state).
Intern::Intern(Intern const& src)
{
	(void)src;
}

/// @brief Copy assignment operator for Intern (no-op since Intern has no state).
Intern&	Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return (*this);
}

/// @brief Destructor for Intern.
Intern::~Intern(void) {}

/// @brief Creates a ShrubberyCreationForm.
/// @param target The target for the form.
/// @return Pointer to a new ShrubberyCreationForm.
static AForm*	createShrubberyCreationForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

/// @brief Creates a RobotomyRequestForm.
/// @param target The target for the form.
/// @return Pointer to a new RobotomyRequestForm.
static AForm*	createRobotomyRequestForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

/// @brief Creates a PresidentialPardonForm.
/// @param target The target for the form.
/// @return Pointer to a new PresidentialPardonForm.
static AForm*	createPresidentialPardonForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

/// @brief Tries to create a form based on the provided name.
/// @param formName The name of the form to create.
/// @param target The target for the form.
/// @return Pointer to the newly created AForm.
/// @throws FormNameUnknown if the name does not match any known form.
AForm*	Intern::makeForm(std::string formName, std::string target)
{
	//dispatch table
	std::string const	name[3] =
		{"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*createForm[3])(std::string const&) =
		{&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (name[i] == formName)
		{
			std::cout << "Intern creates " << formName << "." << std::endl;
			return (createForm[i](target));
		}
	}

	throw FormNameUnknown();
}

/// @brief Exception thrown when an unknown form name is provided.
/// @return A string explaining the error.
char const*	Intern::FormNameUnknown::what() const throw()
{
	return ("form name is unknown");
}
