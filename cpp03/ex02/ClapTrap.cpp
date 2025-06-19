/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:07:23 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 09:51:19 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/// @brief Default constructor. Initializes a ClapTrap with default values.
ClapTrap::ClapTrap(void) :
	name("Default ClapTrap"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " << this->name << std::endl;
}

/// @brief Parameterized constructor. Initializes ClapTrap with a given name.
/// @param newName The name for the ClapTrap.
ClapTrap::ClapTrap(std::string newName) :
	name(newName),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << this->name << std::endl;
}

/// @brief Copy constructor.
/// @param src ClapTrap to copy from.
ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

/// @brief Copy assignment operator.
/// @param rhs ClapTrap to assign from.
/// @return Reference to the assigned ClapTrap.
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

/// @brief Destructor. Called when the object goes out of scope.
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << this->name << std::endl;
}

/// @brief Performs an attack on a target if conditions allow.
/// @param target The target to attack.
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

/// @brief Reduces hit points when taking damage.
/// @param amount Amount of damage taken.
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage points!" << std::endl;
	if (this->hitPoints >= amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}

/// @brief Repairs the ClapTrap if energy and hit points allow.
/// @param amount Amount of hit points to restore.
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

/// @brief Gets the name of the ClapTrap.
/// @return The name string.
std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

/// @brief Gets the current hit points.
/// @return The hit points.
unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

/// @brief Gets the current energy points.
/// @return The energy points.
unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}
