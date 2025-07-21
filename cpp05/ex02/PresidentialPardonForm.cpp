/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:13:27 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 20:21:02 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon Form", 25, 5), target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& newTarget)
	: AForm("Presidential Pardon Form", 25, 5), target(newTarget) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	: AForm(src), target(src.target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::executeAction(void) const //override
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}