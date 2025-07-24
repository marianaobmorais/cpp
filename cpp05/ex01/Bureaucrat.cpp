/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:21:55 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/24 17:34:04 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/// @brief Default constructor for Bureaucrat.
/// Initializes name to "Default Name" and grade to 75.
Bureaucrat::Bureaucrat(void) : name("Default Name"), grade(75) {}


/// @brief Parameterized constructor for Bureaucrat.
/// @param newName Name of the bureaucrat.
/// @param newGrade Grade of the bureaucrat (must be between 1 and 150).
/// @throws GradeTooHighException if newGrade < 1.
/// @throws GradeTooLowException if newGrade > 150.
Bureaucrat::Bureaucrat(std::string const& newName, int newGrade) : name(newName), grade(newGrade)
{
	if (this->grade < 1)
		throw GradeTooHighException();
	if (this->grade > 150)
		throw GradeTooLowException();
}


/// @brief Copy constructor for Bureaucrat.
/// @param src The Bureaucrat to copy from.
Bureaucrat::Bureaucrat(Bureaucrat const& src) : name(src.name), grade(src.grade) {}


/// @brief Copy assignment operator.
/// @param rhs The Bureaucrat to assign from.
/// @return Reference to this Bureaucrat.
/// @throws std::logic_error if trying to assign between bureaucrats with different names.
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs)
	{
		if (this->name != rhs.name)
			throw InvalidCopyAssignmentException();
		this->grade = rhs.grade;
	}
	return (*this);
}

/// @brief Destructor for Bureaucrat.
Bureaucrat::~Bureaucrat(void) {}

/// @brief Gets the bureaucrat's name.
/// @return A constant reference to the name.
std::string const&	Bureaucrat::getName(void) const
{
	return (this->name);
}

/// @brief Gets the bureaucrat's grade.
/// @return The grade as an integer.
int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

/// @brief Increments the bureaucrat's grade.
/// @throws GradeTooHighException if grade would go above 1.
void	Bureaucrat::increment(void)
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade -= 1;
}

/// @brief Decrements the bureaucrat's grade.
/// @throws GradeTooLowException if grade would go below 150.
void	Bureaucrat::decrement(void)
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade += 1;
}

/// @brief Attempts to sign a form on behalf of the bureaucrat.
/// If the bureaucrat's grade is high enough, the form is signed successfully.
/// Otherwise, catches the exception and prints an appropriate error message.
/// @param form The form the bureaucrat attempts to sign.
void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because: " << e.what() << "." << std::endl;
	}
}

/// @brief Exception message for grade too high.
/// @return C-string message indicating grade is too high.
char const*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

/// @brief Exception message for grade too low.
/// @return C-string message indicating grade is too low.
char const*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

/// @brief Exception message for invalid copy assignment.
/// @return A C-style string describing the exception.
char const* Bureaucrat::InvalidCopyAssignmentException::what() const throw()
{
	return ("invalid copy assignment");
}

/// @brief Overloaded output operator for printing Bureaucrat information.
/// @param out Output stream.
/// @param bureaucrat Bureaucrat to print.
/// @return Reference to the output stream.
std::ostream&	operator<<(std::ostream& out, Bureaucrat const& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (out);
}
