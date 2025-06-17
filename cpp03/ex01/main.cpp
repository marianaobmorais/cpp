/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:53:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/17 09:54:24 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Carlos");
	ClapTrap	c(b);
	ClapTrap	d;

	d = b;
	
	std::cout << "----Attack----" << std::endl;
	b.attack("Target1");
	std::cout << b.getName() << " now has " << b.getEnergyPoints() << " energy points left" << std::endl;
	
	std::cout << "----Take damage----" << std::endl;
	b.takeDamage(6);
	std::cout << b.getName() << " now has " << b.getHitPoints() << " hit points left" << std::endl;
	std::cout << b.getName() << " still has " << b.getEnergyPoints() << " energy points left" << std::endl;
	
	std::cout << "----Be repaired----"<< std::endl;
	b.beRepaired(4);
	std::cout << b.getName() << " now has " << b.getHitPoints() << " hit points left" << std::endl;
	std::cout << b.getName() << " now has " << b.getEnergyPoints() << " energy points left" << std::endl;

	std::cout << "----Use all energy points----" << std::endl;
	while (b.getEnergyPoints())
	{
		b.attack("Target2");
		std::cout << b.getName() << " now has " << b.getEnergyPoints() << " energy points left" << std::endl;
	}

	std::cout << "----Take more damage----" << std::endl;
	b.takeDamage(100);
	b.attack("Target3");
	b.beRepaired(10);
	
	return (0);
}