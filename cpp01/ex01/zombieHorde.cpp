/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:26:04 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:16:24 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

/// @brief Creates a horde of zombies with numbered names.
/// @param N Number of zombies to create.
/// @param name Base name to assign to each zombie.
/// @return Pointer to the heap-allocated array of zombies, or NULL if N <= 0.
Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << (i + 1);
		horde[i].setName(name + oss.str());
	}
	return (horde);
}
