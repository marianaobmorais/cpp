/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:16:34 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/07 14:44:28 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure&	Cure::operator=(Cure const& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	std::cout << "Cure copy assingment operator called" << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	std::cout << "cure is cloned" << std::endl;
	return (new Cure(*this)); //deep copy
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}