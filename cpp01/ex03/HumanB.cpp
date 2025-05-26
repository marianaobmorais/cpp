/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:41:24 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:22:25 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/// @brief Constructs a HumanB with a name and no weapon.
HumanB::HumanB(std::string newName) : name(newName), weapon(NULL) {}

/// @brief Destructor for HumanB.
HumanB::~HumanB(void) {}

/// @brief Makes HumanB attack if they have a weapon, or reports unarmed status.
void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapons" << std::endl;
}

/// @brief Assigns a weapon to HumanB.
/// @param newWeapon Reference to the Weapon to assign.
void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}
