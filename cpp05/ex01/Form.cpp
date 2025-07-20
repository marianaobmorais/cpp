/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:48:50 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/20 21:29:21 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

Form::Form(void) : name("Default form"), status(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(std::string const& newName, int const newGradeToSign, int const newGradeToExecute)
	: name(newName), status(false), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(Form const& src) : name(src.name), status(src.status), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {}

Form&	Form::operator=(Form const& rhs)
{
	if (this != &rhs)
	{
		if (this->name != rhs.name || this->gradeToSign != rhs.gradeToSign || this->gradeToExecute != rhs.gradeToExecute)
			throw std::logic_error("Cannot reassign name, grade to sign nor grade to execute");
		this->status = rhs.status;
	}
	return (*this);
}

Form::~Form(void) {}

std::string const&	Form::getName(void) const
{
	return (this->name);
}

bool	Form::getStatus(void) const
{
	return (this->status);
}

int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

char const* Form::GradeTooHighException::what() const throw()
{
	return ("Form: grade is too high");
}

char const* Form::GradeTooLowException::what() const throw()
{
	return ("Form: grade is too low");
}

char const* Form::FormIsAlreadySigned::what() const throw()
{
	return ("Form: already signed");
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (this->status)
		throw FormIsAlreadySigned();
	if (this->gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->status = true;
}

std::ostream&	operator<<(std::ostream& out, Form const& form)
{
	out << form.getName() << ":\nSigned? " << (form.getStatus() ? "yes" : "no") << "\nMinimum grade to sign: " << form.getGradeToSign() << "\nMinimum grade to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}