/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:44:58 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 19:15:54 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/// @brief Default constructor for Dog. Sets type to "Dog".
Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/// @brief Copy constructor for Dog.
/// @param src The Dog object to copy from.
Dog::Dog(Dog const& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/// @brief Copy assignment operator for Dog.
/// @param rhs The Dog object to assign from.
/// @return Reference to this Dog object.
Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

/// @brief Destructor for Dog.
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

/// @brief Makes the Dog sound.
void	Dog::makeSound(void) const
{
	std::cout << this->type << " says: woof woof" << std::endl;
}
