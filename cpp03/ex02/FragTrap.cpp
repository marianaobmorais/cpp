/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:31:10 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 09:37:37 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->name = "Default FragTrap";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(std::string const& newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
}

// FragTrap(FragTrap const& src);
// FragTrap&	operator=(FragTrap const& rhs);
// ~FragTrap(void);

void	FragTrap::highFivesGuys(void)
{
	
}