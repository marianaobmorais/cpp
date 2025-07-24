/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:19:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/24 17:33:40 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/// @brief Default constructor for ShrubberyCreationForm.
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137), target("Default target") {}

/// @brief Constructs a ShrubberyCreationForm targeting a specific location.
/// @param newTarget The name of the target where the shrubbery will be created.
ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
	: AForm("Shrubbery Creation Form", 145, 137), target(newTarget) {}

/// @brief Copy constructor for ShrubberyCreationForm.
/// @param src The form to copy from.
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
	: AForm(src), target(src.target) {}

/// @brief Copy assignment operator for ShrubberyCreationForm.
/// @param rhs The form to copy from.
/// @return Reference to this form.
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

/// @brief Destructor for ShrubberyCreationForm.
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/// @brief Performs the specific action of the ShrubberyCreationForm.
/// Creates a file named "<target>_shrubbery" and writes ASCII art of a tree into it.
/// @throws std::logic_error if the file cannot be opened.
void	ShrubberyCreationForm::executeAction(void) const //override
{
	std::string	filename = this->target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
		throw std::logic_error("Error opening outfile");
	outfile <<
		"    * \n" <<
		"   /.\\ \n" <<
		"  /o..\\ \n" <<
		"  /..o\\ \n" <<
		" /.o..o\\ \n" <<
		" /...o.\\ \n" <<
		"/..o....\\ \n" <<
		"^^^[_]^^^ \n";
	outfile.close();
}
