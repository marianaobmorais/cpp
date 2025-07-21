/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:16:44 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 12:22:32 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	protected:
		void		executeAction(void) const; //override
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
		~ShrubberyCreationForm(void);
};

#endif //SHRUBBERYCREATIONFORM_HPP