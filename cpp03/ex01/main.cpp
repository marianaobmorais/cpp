/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:53:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 11:21:38 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n------------Construct ClapTrap------------" << std::endl;
	ClapTrap c("Carlos");
	std::cout << c.getName() << " has " << c.getHitPoints() << " hit points and " << c.getEnergyPoints() << " energy points" << std::endl;
	c.attack("Target1");
	c.takeDamage(3);
	c.beRepaired(5);
	std::cout << c.getName() << " now has " << c.getHitPoints() << " hit points and " << c.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "\n------------Construct ScavTrap------------" << std::endl;
	ScavTrap s1("Matheus");
	std::cout << s1.getName() << " (original) has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;
	
	std::cout << "\n------------Actions------------" << std::endl;
	std::cout << "*Base class function overwritten*" << std::endl;
	s1.attack("target2");
	std::cout << s1.getName() << " (original) now has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;
	std::cout << "*Derived class new function*" << std::endl;
	s1.guardGate();
	std::cout << "*Base class function not overwritten*" << std::endl;
	s1.takeDamage(90);
	std::cout << s1.getName() << " (original) now has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;
	s1.beRepaired(10);
	std::cout << s1.getName() << " (original) now has " << s1.getHitPoints() << " hit points and " << s1.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "\n------------Copy & Assignment------------" << std::endl;
	ScavTrap s2(s1);
	std::cout << s2.getName() << " (copy) has " << s2.getHitPoints() << " hit points and " << s2.getEnergyPoints() << " energy points" << std::endl;
	ScavTrap s3;
	s3 = s1;
	std::cout << s3.getName() << " (assigned) has " << s3.getHitPoints() << " hit points and " << s3.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "\n------------Destruct------------" << std::endl;
	return (0);
}
