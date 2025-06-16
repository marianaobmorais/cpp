/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:23 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/16 10:50:30 by mariaoli         ###   ########.fr       */
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
	std::cout << "Parameterized constructor called for " << this->getName() << std::endl;
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
	std::cout << "Destructor called for " << this->getName() << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void	ClapTrap::setAttackDamage(unsigned int damage)
{
	this->attackDamage = damage;
}
