/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:55:56 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/21 10:59:45 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	protected:
		void	executeAction(void) const; //override
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
		~RobotomyRequestForm(void);
};

#endif //ROBOTOMYREQUESTFORM_HPP