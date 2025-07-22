/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:00:43 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/22 12:08:30 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/// @brief Default constructor for RobotomyRequestForm.
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", 72, 45), target("Default target") {}

/// @brief Constructs a RobotomyRequestForm targeting a specific individual.
/// @param newTarget The name of the robot to be robotomized.
RobotomyRequestForm::RobotomyRequestForm(std::string newTarget)
	: AForm("Robotomy Request Form", 72, 45), target(newTarget) {}

/// @brief Copy constructor for RobotomyRequestForm.
/// @param src The form to copy from.
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	: AForm(src), target(src.target) {}

/// @brief Copy assignment operator for RobotomyRequestForm.
/// Copies the base class AForm and the target.
/// @param rhs The form to copy from.
/// @return Reference to this form.
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

/// @brief Destructor for RobotomyRequestForm.
RobotomyRequestForm::~RobotomyRequestForm(void) {}

/// @brief Performs the specific action of the RobotomyRequestForm.
/// Prints a message stating that the target has been robotomized successfuly 50% of the time.
void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "* drilling noises *\n";
	if (std::rand() % 2)
		std::cout << this->target << " has been successfully robotomized" << std::endl;
	else
		std::cout << this->target << "'s robotomy has failed" << std::endl;
}
