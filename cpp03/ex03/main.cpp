/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:53:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 20:01:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "\n------------Construct DiamondTrap------------" << std::endl;
	DiamondTrap d1("Edson");
	std::cout << "*Derived class new function*" << std::endl;
	d1.whoAmI();

	std::cout << "\n------------Actions------------" << std::endl;
	std::cout << "*Attack() inherited from ScavTrap class*" << std::endl;
	d1.attack("Target");
	d1.takeDamage(90);
	d1.beRepaired(10);
	d1.whoAmI();
	
	std::cout << "\n------------Copy & Assignment------------" << std::endl;
	DiamondTrap d2(d1);
	d2.whoAmI();
	DiamondTrap d3;
	d3 = d1;
	d3.whoAmI();
	d1.attack("target2");
	d2 = d1;
	d2.whoAmI();

	std::cout << "\n------------Destruct------------" << std::endl;
	return (0);
}
