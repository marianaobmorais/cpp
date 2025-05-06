/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:37:00 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/05 22:06:43 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName) : name(newName){}

Zombie::~Zombie(void)
{
	std::cout << "Destructor message: " << name << " was destroyed" << std::endl;
}

void	Zombie::annouce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
