/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:00:43 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 12:15:58 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", 72, 45), target("Default target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget)
	: AForm("Robotomy Request Form", 72, 45), target(newTarget) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	: AForm(src), target(src.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "* drilling noises *\n" << this->target << "has been successfully robotomized 50% of the time." << std::endl;
}
