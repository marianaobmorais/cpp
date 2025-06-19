/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:31:10 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 20:14:12 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int const	FragTrap::defaultHitPoints = 100;
unsigned int const	FragTrap::defaultEnergyPoints = 100;
unsigned int const	FragTrap::defaultAttackDamage = 30;

/// @brief Default constructor for FragTrap.
/// Initializes name with default and sets hitPoints, energyPoints, and attackDamage
/// to their static default constant values.
FragTrap::FragTrap(void) : ClapTrap("Default FragTrap")
{
	this->hitPoints = FragTrap::defaultHitPoints;
	this->energyPoints = FragTrap::defaultEnergyPoints;
	this->attackDamage =  FragTrap::defaultAttackDamage;
	std::cout << "FragTrap default constructor called for " << this->name << std::endl;
}

/// @brief Parameterized constructor for FragTrap.
/// @param newName The name to assign to the FragTrap.
/// Sets hitPoints, energyPoints, and attackDamage to their static default constants.
FragTrap::FragTrap(std::string const& newName) : ClapTrap(newName)
{
	this->hitPoints = FragTrap::defaultHitPoints;
	this->energyPoints = FragTrap::defaultEnergyPoints;
	this->attackDamage =  FragTrap::defaultAttackDamage;
	std::cout << "FragTrap parameterized constructor called for " << this->name << std::endl;
}

/// @brief Copy constructor for FragTrap.
/// @param src The FragTrap to copy from.
FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/// @brief Copy assignment operator for FragTrap.
/// @param rhs The FragTrap to assign from.
/// @return Reference to the updated object.
FragTrap&	FragTrap::operator=(FragTrap const& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

/// @brief Destructor for FragTrap.
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

/// @brief Prints a positive high-fives request message.
void	FragTrap::highFivesGuys(void)
{
	std::cout << "This is a positive high-fives request :-)" << std::endl;
}
