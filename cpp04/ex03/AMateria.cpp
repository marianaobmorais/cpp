/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:43:52 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/03 19:08:35 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : type("Undefined type")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& newType) : type(newType)
{
	std::cout << "AMateria paremetized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const& src) : type(src.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
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

std::string const&	AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* Nothing happens to " << target.getName() << " *" << std::endl;
}