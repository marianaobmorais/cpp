/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:28:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/24 17:30:58 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				status;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		Form(void);
		Form(std::string const& newName, int const newGradeToSign, int const newGradeToExecute);
		Form(Form const& src);
		Form&				operator=(Form const& rhs);
		~Form(void);

		std::string const&	getName(void) const;
		bool				getStatus(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const*	what() const throw(); //override
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //override
		};

		class FormIsAlreadySignedException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //override
		};

		class InvalidCopyAssignmentException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //override
		};

		void	beSigned(Bureaucrat const& bureaucrat);
};

std::ostream&	operator<<(std::ostream& out, Form const& form);

#endif //FORM_HPP