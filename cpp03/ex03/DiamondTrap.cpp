/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:58:10 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 20:10:16 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/// @brief Default constructor for DiamondTrap.
/// Initializes with default names and values from FragTrap and ScavTrap.
DiamondTrap::DiamondTrap(void) :
	ClapTrap("Default_clap_name"),
	name("Default")
{
	this->hitPoints = FragTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap default constructor called for " << this->name << std::endl;
}


/// @brief Parameterized constructor for DiamondTrap.
/// @param newName The name to assign to the DiamondTrap.
DiamondTrap::DiamondTrap(std::string const& newName) :
	ClapTrap(newName + "_clap_name"),
	name(newName)
{
	this->hitPoints = FragTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap parameterized constructor called for " << this->name << std::endl;
}

/// @brief Copy constructor for DiamondTrap.
/// @param src The DiamondTrap to copy from.
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


/// @brief Copy assignment operator for DiamondTrap.
/// @param rhs The DiamondTrap to assign from.
/// @return Reference to the updated object.
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const&rhs)
{
	if (this != &rhs)
	{
		FragTrap::operator=(rhs);
		this->name = rhs.name;
	}
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	return (*this);
}

/// @brief Destructor for DiamondTrap.
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

/// @brief Displays both the DiamondTrap and ClapTrap names.
void	DiamondTrap::whoAmI(void)
{
	std::cout << "\n**Who am I?**\n";
	std::cout << "*DiamondTrap name: " << this->name << "\n";
	std::cout << "*ClapTrap name: " << ClapTrap::getName() << "\n" << std::endl;
}

/// @brief Performs an attack using ScavTrap's implementation.
/// @param target The target to attack.
void	DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}
