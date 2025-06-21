/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:55:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 19:19:29 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/// @brief Default constructor. Initializes type to "WrongUndefined type".
WrongAnimal::WrongAnimal(void) : type("WrongUndefined type")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

/// @brief Copy constructor.
/// @param src The WrongAnimal object to copy from.
WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

/// @brief Copy assignment operator.
/// @param rhs The WrongAnimal object to assign from.
/// @return Reference to this WrongAnimal.
WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/// @brief Destructor.
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/// @brief Prints the sound this WrongAnimal makes.
void	WrongAnimal::makeSound(void) const
{
	std::cout << this->type << " says: !#RRR%$#%@$Tw" << std::endl;
}

/// @brief Returns the type of this WrongAnimal.
/// @return The type as a string.
std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
