/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:13:27 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/24 17:35:51 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/// @brief Default constructor for PresidentialPardonForm.
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon Form", 25, 5), target("Default Target") {}

/// @brief Constructs a PresidentialPardonForm targeting a specific individual.
/// @param newTarget The name of the person to be pardoned.
PresidentialPardonForm::PresidentialPardonForm(std::string const& newTarget)
	: AForm("Presidential Pardon Form", 25, 5), target(newTarget) {}

/// @brief Copy constructor for PresidentialPardonForm.
/// @param src The form to copy from.
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	: AForm(src), target(src.target) {}

/// @brief Copy assignment operator for PresidentialPardonForm.
/// Copies the base class AForm and the target.
/// @param rhs The form to copy from.
/// @return Reference to this form.
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

/// @brief Destructor for PresidentialPardonForm.
PresidentialPardonForm::~PresidentialPardonForm(void) {}

/// @brief Performs the specific action of the PresidentialPardonForm.
/// Prints a message stating that the target has been pardoned.
void	PresidentialPardonForm::executeAction(void) const //override
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
