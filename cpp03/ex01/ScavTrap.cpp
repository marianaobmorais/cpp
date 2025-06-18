/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:36:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/18 19:28:12 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->name = "Default ScavTrap";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string const& newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor called for " << this->name << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const& src) //: ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
		//ClapTrap::operator=(rhs);
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}


ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void	ScavTrap::attack(std::string const& target)
{
	if (this->energyPoints <= 0 && this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " cannot attack. Not enough energy points nor hit points." << std::endl;
	else if (this->energyPoints <= 0)
		std::cout << "ScavTrap " << this->name << " cannot attack. Not enough energy point." << std::endl;
	else if (this->hitPoints <= 0)
		std::cout << "ScavTrap " << this->name << " cannot attack. Not enough hit points." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}