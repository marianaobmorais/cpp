/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:48:50 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 20:15:47 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

/// @brief Default constructor. Initializes a default form with max grades.
AForm::AForm(void) : name("Default form"), status(false), gradeToSign(150), gradeToExecute(150) {}

/// @brief Parametric constructor. Initializes a form with the given name and grade limits.
/// @param newName The name of the form.
/// @param newGradeToSign Grade required to sign the form.
/// @param newGradeToExecute Grade required to execute the form.
/// @throws GradeTooHighException if any grade is less than 1.
/// @throws GradeTooLowException if any grade is greater than 150.
AForm::AForm(std::string const& newName, int const newGradeToSign, int const newGradeToExecute)
	: name(newName), status(false), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
}

/// @brief Copy constructor.
/// @param src The source Form to copy.
AForm::AForm(AForm const& src) : name(src.name), status(src.status), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {}

/// @brief Copy assignment operator.
/// @param rhs The source Form to assign from.
/// @return A reference to this Form.
/// @throws std::logic_error if the name or required grades differ.
AForm&	AForm::operator=(AForm const& rhs)
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
AForm::~AForm(void) {}

/// @brief Gets the name of the form.
/// @return A constant reference to the form name.
std::string const&	AForm::getName(void) const
{
	return (this->name);
}

/// @brief Gets the signature status of the form.
/// @return True if signed, false otherwise.
bool	AForm::getStatus(void) const
{
	return (this->status);
}

/// @brief Gets the grade required to sign the form.
/// @return Integer grade value.
int	AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

/// @brief Gets the grade required to execute the form.
/// @return Integer grade value.
int	AForm::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

/// @brief Allows a Bureaucrat to sign the form if their grade is sufficient.
/// @param bureaucrat The Bureaucrat attempting to sign the form.
/// @throws FormIsAlreadySigned if the form has already been signed.
/// @throws GradeTooLowException if the bureaucrat’s grade is too low.
void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (this->status)
		throw FormIsAlreadySignedException();
	if (this->gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->status = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!this->status)
		throw FormNotSignedException();
	if (this->gradeToExecute < executor.getGrade())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->name << "." << std::endl;
	this->executeAction();
}

/// @brief Exception message for grades that are too high.
/// @return C-string description of the error.
char const* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

/// @brief Exception message for grades that are too low.
/// @return C-string description of the error.
char const* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

/// @brief Exception message for trying to sign an already signed form.
/// @return C-string description of the error.
char const* AForm::FormIsAlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

/// @brief Exception message for trying to execute an form that wasn't signed.
/// @return C-string description of the error.
char const* AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

/// @brief Exception message for invalid copy assignment.
/// @return A C-style string describing the exception.
char const* AForm::InvalidCopyAssignmentException::what() const throw()
{
	return ("invalid copy assignment");
}

/// @brief Overloaded output operator for printing a form’s state.
/// @param out The output stream.
/// @param form The form to print.
/// @return The output stream.
std::ostream&	operator<<(std::ostream& out, AForm const& form)
{
	out << form.getName() << ":\nSigned? " << (form.getStatus() ? "yes" : "no") << "\nMinimum grade to sign: " << form.getGradeToSign() << "\nMinimum grade to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}