/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:12:34 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/04 10:36:53 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
{
	this->type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src) //I guess this is right?
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice&	Ice::operator=(Ice const& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	std::cout << "Ice copy assignment operator called" << std::endl;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this)); //deep copy
}

void	Ice::use(ICharacter& target) //probably need to count down the materia??
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}