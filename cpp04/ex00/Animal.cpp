/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:55:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/22 10:20:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/// @brief Default constructor initializing type to "Undefined type".
Animal::Animal(void) : type("Undefined type")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/// @brief Copy constructor.
/// @param src Reference to the Animal to copy from.
Animal::Animal(Animal const& src) : type(src.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/// @brief Copy assignment operator.
/// @param rhs Reference to the Animal to assign from.
/// @return Reference to this Animal.
Animal&	Animal::operator=(Animal const& rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/// @brief Destructor.
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/// @brief Prints the animal's sound.
/// Default sound is a placeholder.
void	Animal::makeSound(void) const
{
	std::cout << this->type << " says: !#RRR%$#%@$Tw" << std::endl;
}

/// @brief Getter for the animal's type.
/// @return The type of the animal as a string.
std::string	Animal::getType(void) const
{
	return (this->type);
}
