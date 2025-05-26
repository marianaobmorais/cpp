/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:32:55 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:23:02 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/// @brief Constructs a Weapon with the given type.
Weapon::Weapon(std::string newType) : type(newType){}

/// @brief Destructor for Weapon.
Weapon::~Weapon(void){}

/// @brief Returns the type of the weapon.
/// @return The weapon type as a string.
const std::string	Weapon::getType(void)
{
	return (type);
}

/// @brief Sets a new type for the weapon.
/// @param newType The new weapon type.
void	Weapon::setType(std::string newType)
{
	type = newType;
}
