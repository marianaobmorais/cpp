/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:37:15 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:14:22 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Allocates a new Zombie on the heap.
/// @param name The name of the zombie.
/// @return Pointer to the newly created Zombie.
Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}
