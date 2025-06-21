/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:55:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 20:10:26 by mariaoli         ###   ########.fr       */
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
Animal::Animal(Animal const& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
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

// /// @brief Prints the animal's sound.
// /// Default sound is a placeholder.
// void	Animal::makeSound(void) const
// {
// 	std::cout << this->type << " says: !#RRR%$#%@$Tw" << std::endl;
// }

/// @brief Getter for the animal's type.
/// @return The type of the animal as a string.
std::string	Animal::getType(void) const
{
	return (this->type);
}

/// @brief Attempts to set an idea at the given index.
/// @param index The position to set the idea (ignored).
/// @param idea The idea string to set (ignored).
/// @note Base Animal has no brain; this function does nothing.
void	Animal::setIdea(int, std::string const&)
{
	std::cout << "setIdea: No brain, no idea!" << std::endl;
}

/// @brief Attempts to get an idea at the given index.
/// @param index The position to retrieve the idea from (ignored).
/// @return A default message since base Animal has no ideas.
std::string	Animal::getIdea(int) const
{
	return ("getIdea: No brain, no idea!");
}
