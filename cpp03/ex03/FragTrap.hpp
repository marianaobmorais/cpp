/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:18:50 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:54:51 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const& newName);
		FragTrap(FragTrap const& src);
		FragTrap&	operator=(FragTrap const& rhs);
		~FragTrap(void);

		void	highFivesGuys(void);

		static unsigned int const	defaultHitPoints;
		static unsigned int const	defaultEnergyPoints;
		static unsigned int const	defaultAttackDamage;
};

#endif //FRAGTRAP_HPP