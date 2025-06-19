/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:36:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 10:38:37 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/// @brief Default constructor for ScavTrap.
/// Initializes a ScavTrap with default name and predefined hit/energy/attack values.
ScavTrap::ScavTrap(void) : ClapTrap("Default ScavTrap")
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called for " << this->name << std::endl;
}

/// @brief Parameterized constructor for ScavTrap.
/// @param newName The name to assign to the ScavTrap.
ScavTrap::ScavTrap(std::string const& newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor called for " << this->name << std::endl;
}

/// @brief Copy constructor for ScavTrap.
/// @param src The ScavTrap to copy from.
ScavTrap::ScavTrap(ScavTrap const& src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

/// @brief Copy assignment operator.
/// @param rhs The ScavTrap to assign from.
/// @return Reference to the updated object.
ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

/// @brief Destructor for ScavTrap. Called when the object goes out of scope.
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

/// @brief Performs an attack on a target if conditions allow.
/// @param target The target to attack.
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

/// @brief Activates Gate Keeper mode for the ScavTrap.
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}
