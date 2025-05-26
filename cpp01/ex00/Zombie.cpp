/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:37:00 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:14:59 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/// @brief Constructs a Zombie with the given name.
/// @param newName The zombie's name.
Zombie::Zombie(std::string newName) : name(newName){}

/// @brief Destructor. Announces the zombie's destruction.
Zombie::~Zombie(void)
{
	std::cout << "Destructor message: " << name << " was destroyed" << std::endl;
}

/// @brief Makes the zombie announce itself.
void	Zombie::annouce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
