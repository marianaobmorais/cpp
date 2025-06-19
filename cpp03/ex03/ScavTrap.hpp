/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:18:50 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:55:45 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const& newName);
		ScavTrap(ScavTrap const& src);
		ScavTrap&	operator=(ScavTrap const& rhs);
		~ScavTrap(void);
		
		void	attack(std::string const& target);
		void	guardGate(void);

		static unsigned int const	defaultHitPoints;
		static unsigned int const	defaultEnergyPoints;
		static unsigned int const	defaultAttackDamage;
};

#endif