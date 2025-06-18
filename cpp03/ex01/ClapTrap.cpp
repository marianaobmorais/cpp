/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:23 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/18 20:01:39 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	name("Default ClapTrap"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string newName) :
	name(newName),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}
ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap destructor called for " << this->name << std::endl;
}

void	ClapTrap::attack(std::string const& target)
{
	if (this->energyPoints <= 0 && this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot attack. Not enough energy points nor hit points." << std::endl;
	else if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot attack. Not enough energy point." << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot attack. Not enough hit points." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage points!" << std::endl;
	if (this->hitPoints >= amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 && this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot attack. Not enough energy points nor hit points." << std::endl;
	else if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot repair itself. Not enough energy points." << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " cannot repair itself. Not enough hit points." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " repairs itself with " << amount << " hit points!" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
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
