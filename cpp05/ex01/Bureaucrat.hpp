/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:37:44 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const& newName, int newGrade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat&			operator=(Bureaucrat const& rhs);
		~Bureaucrat(void);

		std::string const&	getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);

		void				signForm(Form& form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //override
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //override
		};

		class InvalidCopyAssignmentException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //override
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat);

#endif //BUREAUCRAT_HPP