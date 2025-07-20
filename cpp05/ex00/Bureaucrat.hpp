/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:37:44 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/20 13:20:26 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

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

		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //C++98 exception specification, means it won’t throw anything
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const* what() const throw(); //C++98 exception specification, means it won’t throw anything
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs);

#endif //BUREAUCRAT_HPP