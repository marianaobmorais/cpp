/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:25:24 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 19:13:21 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/// @brief Default constructor for Cat. Sets type to "Cat".
Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/// @brief Copy constructor for Cat.
/// @param src The Cat object to copy from.
Cat::Cat(Cat const& src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/// @brief Copy assignment operator for Cat.
/// @param rhs The Cat object to assign from.
/// @return Reference to this Cat object.
Cat&	Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

/// @brief Destructor for Cat.
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

/// @brief Makes the Cat sound.
void	Cat::makeSound(void) const
{
	std::cout << this->type << " says: meow meow" << std::endl;
}