/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:37:36 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:14:34 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

/// @brief Creates a Zombie on the stack and makes it announce itself.
/// @param name The name of the zombie.
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.annouce();
}
