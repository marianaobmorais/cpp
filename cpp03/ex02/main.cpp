/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:53:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 15:28:28 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "\n------------Construct FragTrap------------" << std::endl;
	FragTrap f1("Luciano");
	std::cout << f1.getName() << " (original) has " << f1.getHitPoints() << " hit points and " << f1.getEnergyPoints() << " energy points" << std::endl;
	
	std::cout << "\n------------Actions------------" << std::endl;
	std::cout << "*Derived class new function*" << std::endl;
	f1.highFivesGuys();
	std::cout << "*Base class function not overwritten*" << std::endl;
	f1.attack("Target");
	std::cout << f1.getName() << " now has " << f1.getHitPoints() << " hit points and " << f1.getEnergyPoints() << " energy points" << std::endl;
	f1.takeDamage(90);
	std::cout << f1.getName() << " now has " << f1.getHitPoints() << " hit points and " << f1.getEnergyPoints() << " energy points" << std::endl;
	f1.beRepaired(10);
	std::cout << f1.getName() << " now has " << f1.getHitPoints() << " hit points and " << f1.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "\n------------Copy & Assignment------------" << std::endl;
	FragTrap f2(f1);
	std::cout << f2.getName() << " (copy) has " << f2.getHitPoints() << " hit points and " << f2.getEnergyPoints() << " energy points" << std::endl;
	FragTrap f3;
	f3 = f1;
	std::cout << f3.getName() << " (assigned) has " << f3.getHitPoints() << " hit points and " << f3.getEnergyPoints() << " energy points" << std::endl;

	std::cout << "\n------------Destruct------------" << std::endl;
	return (0);
}