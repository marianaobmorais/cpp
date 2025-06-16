/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:23 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/16 20:30:05 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	name("Default name"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "Default constructor called" <<std::endl;
}

ClapTrap::ClapTrap(std::string newName) :
	name(newName),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "Parameterized constructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	//using accessor function here is redundant?
	std::cout << "Destructor called for " << this->name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		//using accessor function here is redundant?
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else if (energyPoints <= 0)
		std::cout << "ClapTrap cannot attack. Not enough energy points." << std::endl;
	else if (hitPoints <= 0)
		std::cout << "ClapTrap cannot attack. Not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	//using accessor function here is redundant?
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage!" << std::endl;
	if (hitPoints >= amount)
		hitPoints -= amount;
	else
		hitPoints = 0;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		//using accessor function here is redundant?
		std::cout << "ClapTrap " << this->name << " repairs itself with " << amount << " points of hit!" << std::endl;
		energyPoints--;
		hitPoints += amount;
	}
	else if (energyPoints <= 0)
		std::cout << "ClapTrap cannot repair itself. Not enough energy points." << std::endl;
	else if (hitPoints <= 0)
		std::cout << "ClapTrap cannot repair itself. Not enough hit points." << std::endl;
}

// std::string	ClapTrap::getName(void) const
// {
// 	return (this->name);
// }

// unsigned int	ClapTrap::getHitPoints(void) const
// {
// 	return (this->hitPoints);
// }

// unsigned int	ClapTrap::getEnergyPoints(void) const
// {
// 	return (this->energyPoints);
// }

// unsigned int	ClapTrap::getAttackDamage(void) const
// {
// 	return (this->attackDamage);
// }

// void	ClapTrap::setAttackDamage(unsigned int damage)
// {
// 	this->attackDamage = damage;
// }
