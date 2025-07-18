/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:05:00 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/07 12:08:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

#define SLOTS 4

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[SLOTS];
	public:
		Character(void);
		Character(std::string const& newName);
		Character(Character const& src);
		Character&	operator=(Character const& rhs);
		~Character(void);

		std::string const&	getName(void) const; //override
		void				equip(AMateria* m); //override
		void				unequip(int idx); //override
		void				use(int idx, ICharacter& target); //override
};

#endif //CHARACTER_HPP