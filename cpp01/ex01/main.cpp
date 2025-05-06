/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:29:19 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/06 19:02:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void)
{
	int	N = 5;

	Zombie	*horde = zombieHorde(N, "Cleiton");
	if (horde)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	return (0);
}