/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:53:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/18 19:33:40 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "----Construct ClapTrap----" << std::endl;
	ClapTrap c("Carlos");
	c.attack("Target1");
	c.takeDamage(3);
	c.beRepaired(5);
	std::cout << c.getName() << " now has " << c.getHitPoints() << " hit points and " << c.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "----Construct ScavTrap----" << std::endl;
	ScavTrap s1("Matheus");
	std::cout << s1.getName() << " has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;
	s1.attack("target2");
	std::cout << s1.getName() << " now has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;
	s1.guardGate();
	s1.takeDamage(90);
	std::cout << s1.getName() << " now has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;
	s1.beRepaired(10);
	std::cout << s1.getName() << " now has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "----Copy & Assignment----" << std::endl;
	ScavTrap s2(s1);
	ScavTrap s3;
	s3 = s1;
	std::cout << s3.getName() << " (copy) now has " << s3.getHitPoints() << " hit points and " << s3.getEnergyPoints() << " energy points" << std::endl;


	std::cout << "----Destruct----" << std::endl;
	return (0);
}
