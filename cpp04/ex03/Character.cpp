/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:43:28 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/04 14:03:36 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) : name("Undefined name")
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const& newName) : name(newName)
{
	std::cout << "Character parameterized constructor called for" << name << std::endl;
}

Character::Character(Character const& src) : name(src.name)
{
	for (int i = 0; i < SLOTS; i++)
	{
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone(); //deep copy
		else
			this->inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}
Character&	Character::operator=(Character const& rhs) //: name(rhs.name) //it doesnt work bc it's not a constructor?
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < SLOTS; i++)
		{
			delete (this->inventory[i]);
			this->inventory[i] = NULL;
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone(); //deep copy
		}
	}
	std::cout << "Character copy assignment operator called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < SLOTS; i++)
	{
		delete (this->inventory[i]);
		this->inventory[i] = NULL;
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const&	Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < SLOTS; i++)
		{
			if (!this->inventory[i])
			{
				this->inventory[i] = m;
				std::cout << this->name << " equiped inventory with " << m->getType() << std::endl;
				break ;
			}
		}
	}
	//write warning?
}
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx >= 3)
	{
		if (inventory[idx])
			inventory[idx] = NULL; //won't it leak??
	}
}
void	Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
	//else: no spell available in slot <idx>?
}