/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:36:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 20:17:33 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int const	ScavTrap::defaultHitPoints = 100;
unsigned int const	ScavTrap::defaultEnergyPoints = 50;
unsigned int const	ScavTrap::defaultAttackDamage = 20;

/// @brief Default constructor for ScavTrap.
/// Initializes name with default and sets hitPoints, energyPoints, and attackDamage
/// to their static default constant values.
ScavTrap::ScavTrap(void) : ClapTrap("Default ScavTrap")
{
	this->hitPoints = ScavTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = ScavTrap::defaultAttackDamage;
	std::cout << "ScavTrap default constructor called for " << this->name << std::endl;
}

/// @brief Parameterized constructor for ScavTrap.
/// @param newName The name to assign to the ScavTrap.
/// Sets hitPoints, energyPoints, and attackDamage to their static default constants.
ScavTrap::ScavTrap(std::string const& newName) : ClapTrap(newName)
{
	this->hitPoints = ScavTrap::defaultHitPoints;
	this->energyPoints = defaultEnergyPoints;
	this->attackDamage = ScavTrap::defaultAttackDamage;
	std::cout << "ScavTrap parameterized constructor called for " << this->name << std::endl;
}

/// @brief Copy constructor for ScavTrap.
/// @param src The ScavTrap to copy from.
ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/// @brief Copy assignment operator.
/// @param rhs The ScavTrap to assign from.
/// @return Reference to the updated object.
ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
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
