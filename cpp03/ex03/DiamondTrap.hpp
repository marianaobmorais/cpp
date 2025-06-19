/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:31:39 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/19 11:55:24 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const& newName);
		DiamondTrap(DiamondTrap const& src);
		DiamondTrap&	operator=(DiamondTrap const&rhs);
		~DiamondTrap(void);

		void	whoAmI(void);
};

#endif //DIAMONDTRAP_HPP