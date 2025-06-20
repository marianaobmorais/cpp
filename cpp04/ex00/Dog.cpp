/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:44:58 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/20 23:32:43 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void)
{
	std::cout << "Dog says: woof woof" << std::endl;
}
