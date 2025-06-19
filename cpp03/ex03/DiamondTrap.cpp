/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:58:10 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 13:54:42 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap("Default_clap_name"),
	FragTrap(), //why not use parameter?
	ScavTrap(), //why not use parameter?
	name("default")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& newName) :
	ClapTrap(newName + "_clap_name"),
	FragTrap(), //why not use parameter?
	ScavTrap(), //why not use parameter?
	name(newName)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap parameterized constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) :
	ClapTrap(src),
	FragTrap(src),
	ScavTrap(src),
	name(src.name) //need to init new data member
{
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const&rhs)
{
	if (this != &rhs)
	{
		FragTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		name = rhs.name;
	}
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

// void	whoAmI(void);

// // whoAmI() prints DiamondTrap's own name and ClapTrap's name
// void	DiamondTrap::whoAmI(void)
// {
// 	std::cout << "DiamondTrap name: " << this->name << "\n";
// 	std::cout << "ClapTrap name: " << ClapTrap::name << "\n";
// }

// // Use ScavTrap's attack method explicitly to resolve ambiguity
// void DiamondTrap::attack(const std::string& target)
// {
// 	ScavTrap::attack(target);
// }