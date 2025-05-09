/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:44:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/08 15:33:09 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string newName, Weapon &newWeapon);
		~HumanA(void);
		void	attack(void);
};

#endif //HUMANA_HPP