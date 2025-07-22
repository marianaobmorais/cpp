/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:28:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 10:30:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				status;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		AForm(void);
		AForm(std::string const& newName, int const newGradeToSign, int const newGradeToExecute);
		AForm(AForm const& src);
		AForm&	operator=(AForm const& rhs);
		virtual ~AForm(void);

		std::string const&	getName(void) const;
		bool				getStatus(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(Bureaucrat const& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const;
		virtual void		executeAction(void) const = 0;

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

		class FormNotSignedException : public std::exception
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

std::ostream&	operator<<(std::ostream& out, AForm const& form);

#endif //FORM_HPP