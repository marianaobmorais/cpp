/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:21:55 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/20 15:35:14 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat(void) : name("Default Name"), grade(75) {}

Bureaucrat::Bureaucrat(std::string const& newName, int newGrade) : name(newName)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	if (newGrade > 150)
		throw GradeTooLowException();
	//else??
	this->grade = newGrade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name(src.name), grade(src.grade) {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs)
	{
		if (this->name != rhs.name)
			throw std::logic_error("Copy assignment of Bureaucrats with different names is not allowed");
		this->grade = rhs.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

std::string const&	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::increment(void)
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade -= 1;
}

void	Bureaucrat::decrement(void)
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade += 1;
}

char const*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high: must be >= 1");
}

char const* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low: must be <= 150");
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}