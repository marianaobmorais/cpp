/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:29:55 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/08 14:39:02 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string			type;
	public:
		Weapon(std::string newType);
		~Weapon(void);
		const std::string	getType(void);
		void				setType(std::string newType);
};

#endif //WEAPON_HPP