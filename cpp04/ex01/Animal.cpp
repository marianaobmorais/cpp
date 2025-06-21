/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:55:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 18:34:07 by mariaoli         ###   ########.fr       */
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
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << this->type << " says: !#RRR%$#%@$Tw" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::setIdea(int, std::string const&)
{
	std::cout << "setIdea: No brain, no idea!" << std::endl;
}

std::string	Animal::getIdea(int) const
{
	return ("getIdea: No brain, no idea!");
}
