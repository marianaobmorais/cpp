/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:41:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 10:45:02 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& src);
		Intern&	operator=(Intern const& rhs);
		~Intern(void);

		AForm*	makeForm(std::string formName, std::string target);
};

#endif //INTERN_HPP