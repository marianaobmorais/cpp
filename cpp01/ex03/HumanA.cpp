/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:23:22 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:20:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/// @brief Constructs a HumanA with a name and a reference to a Weapon.
HumanA::HumanA(std::string newName, Weapon &newWeapon) :
	name(newName), weapon(newWeapon) {}

/// @brief Destructor for HumanA.
HumanA::~HumanA(void) {}

/// @brief Makes HumanA attack with their weapon.
void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}