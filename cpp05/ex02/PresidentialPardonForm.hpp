/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:01:47 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/20 23:06:41 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const& newTarget);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
		~PresidentialPardonForm(void);

		void	execute(Bureaucrat const & executor) const; //override
};

#endif //PRESIDENTIALPARDONFORM_HPP