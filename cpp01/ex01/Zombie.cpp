/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:28:53 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/03 19:49:58 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Default constructor for Zombie.
Zombie::Zombie(void){}

/// @brief Destructor. Announces the zombie's destruction.
Zombie::~Zombie(void)
{
	std::cout << "Destructor message: " << name << " was destroyed" << std::endl;
}

/// @brief Makes the zombie announce itself.
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/// @brief Sets the zombie's name.
/// @param newName The name to assign to the zombie.
void	Zombie::setName(std::string newName)
{
	name = newName;
}


