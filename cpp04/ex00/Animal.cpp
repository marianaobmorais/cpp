/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:55:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/20 23:21:03 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Undefined type")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal&	Animal::operator=(Animal const& rhs)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void)
{
	std::cout << "Undefined sound: !#RRR%$#%@$Tw" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
