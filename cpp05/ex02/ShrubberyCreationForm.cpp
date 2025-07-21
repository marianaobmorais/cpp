/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:19:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 12:43:27 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137), target("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
	: AForm("Shrubbery Creation Form", 145, 137), target(newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
	: AForm(src), target(src.target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::executeAction(void) const //override
{
	std::string	filename = this->target + "_shrubbery";
	std::ofstream	outfile(filename.c_str()); //what is happening here?
	if (!outfile.good()) //too many checks?
		throw std::logic_error("Error creating outfile");
	if (outfile.is_open())
	{
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
}