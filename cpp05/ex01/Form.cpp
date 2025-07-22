/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:48:50 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 18:17:18 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

/// @brief Default constructor. Initializes a default form with max grades.
Form::Form(void) : name("Default form"), status(false), gradeToSign(150), gradeToExecute(150) {}

/// @brief Parametric constructor. Initializes a form with the given name and grade limits.
/// @param newName The name of the form.
/// @param newGradeToSign Grade required to sign the form.
/// @param newGradeToExecute Grade required to execute the form.
/// @throws GradeTooHighException if any grade is less than 1.
/// @throws GradeTooLowException if any grade is greater than 150.
Form::Form(std::string const& newName, int const newGradeToSign, int const newGradeToExecute)
	: name(newName), status(false), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
}

/// @brief Copy constructor.
/// @param src The source Form to copy.
Form::Form(Form const& src) : name(src.name), status(src.status), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {}

/// @brief Copy assignment operator.
/// @param rhs The source Form to assign from.
/// @return A reference to this Form.
/// @throws std::logic_error if the name or required grades differ.
Form&	Form::operator=(Form const& rhs)
{
	if (this != &rhs)
	{
		if (this->name != rhs.name || this->gradeToSign != rhs.gradeToSign || this->gradeToExecute != rhs.gradeToExecute)
			throw InvalidCopyAssignmentException();
		this->status = rhs.status;
	}
	return (*this);
}

/// @brief Destructor for Form.
Form::~Form(void) {}

/// @brief Gets the name of the form.
/// @return A constant reference to the form name.
std::string const&	Form::getName(void) const
{
	return (this->name);
}

/// @brief Gets the signature status of the form.
/// @return True if signed, false otherwise.
bool	Form::getStatus(void) const
{
	return (this->status);
}

/// @brief Gets the grade required to sign the form.
/// @return Integer grade value.
int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

/// @brief Gets the grade required to execute the form.
/// @return Integer grade value.
int	Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

/// @brief Exception message for grades that are too high.
/// @return C-string description of the error.
char const* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

/// @brief Exception message for grades that are too low.
/// @return C-string description of the error.
char const* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

/// @brief Exception message for trying to sign an already signed form.
/// @return C-string description of the error.
char const* Form::FormIsAlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

/// @brief Exception message for invalid copy assignment.
/// @return A C-style string describing the exception.
char const* Form::InvalidCopyAssignmentException::what() const throw()
{
	return ("invalid copy assignment");
}

/// @brief Allows a Bureaucrat to sign the form if their grade is sufficient.
/// @param bureaucrat The Bureaucrat attempting to sign the form.
/// @throws FormIsAlreadySigned if the form has already been signed.
/// @throws GradeTooLowException if the bureaucrat’s grade is too low.
void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (this->status)
		throw FormIsAlreadySignedException();
	if (this->gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->status = true;
}

/// @brief Overloaded output operator for printing a form’s state.
/// @param out The output stream.
/// @param form The form to print.
/// @return The output stream.
std::ostream&	operator<<(std::ostream& out, Form const& form)
{
	std::cout << "\n[";
	out << form.getName() << ":\nSigned? " << (form.getStatus() ? "yes" : "no") << "\nMinimum grade to sign: " << form.getGradeToSign() << "\nMinimum grade to execute: " << form.getGradeToExecute();
	std::cout << "]\n" << std::endl;
	return (out);
}