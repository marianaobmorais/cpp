/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:43:52 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/07 14:46:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria*	AMateria::floor[1024] = {NULL};
int			AMateria::floorIdx = 0;

AMateria::AMateria(void) : type("Undefined type")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& newType) : type(newType)
{
	std::cout << "AMateria parametized constructor called for " << newType << std::endl;
}

AMateria::AMateria(AMateria const& src) : type(src.type)
{
	std::cout << "AMateria copy constructor called for " << src.getType() << std::endl;
}

AMateria&	AMateria::operator=(AMateria const& rhs)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const&	AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* Nothing happens to " << target.getName() << " *" << std::endl;
}

bool	AMateria::stash(AMateria *m)
{
	if (floorIdx < 1024 && m)
	{
		floor[floorIdx++] = m;
		return (true);
	}
	return (false);
}

void	AMateria::cleanFloor(void)
{
	for (int i = 0; i < MAX_FLOOR; i++)
		delete floor[i];
	floorIdx = 0;
	std::cout << "Floor was cleaned up" << std::endl;
}