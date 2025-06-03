/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:37:36 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/03 19:49:30 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Creates a Zombie on the stack and makes it announce itself.
/// @param name The name of the zombie.
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.annouce();
}
