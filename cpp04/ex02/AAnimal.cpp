/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:55:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/22 10:20:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/// @brief Default constructor initializing type to "Undefined type".
AAnimal::AAnimal(void) : type("Undefined type")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

/// @brief Copy constructor.
/// @param src Reference to the Animal to copy from.
AAnimal::AAnimal(AAnimal const& src) : type(src.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

/// @brief Copy assignment operator.
/// @param rhs Reference to the AAnimal to assign from.
/// @return Reference to this AAnimal.
AAnimal&	AAnimal::operator=(AAnimal const& rhs)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/// @brief Destructor.
AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

// This would be the default sound for an AAnimal,
// but makeSound is declared as pure virtual (= 0),
// so AAnimal is abstract and can't be instantiated.
// Uncommenting this would provide a definition, but AAnimal would still be abstract
// void	AAnimal::makeSound(void) const
// {
// 	std::cout << this->type << " says: !#RRR%$#%@$Tw" << std::endl;
// }

/// @brief Getter for the animal's type.
/// @return The type of the animal as a string.
std::string	AAnimal::getType(void) const
{
	return (this->type);
}

/// @brief Attempts to set an idea at the given index.
/// @param index The position to set the idea (ignored).
/// @param idea The idea string to set (ignored).
/// @note Base AAnimal has no brain; this function does nothing.
void	AAnimal::setIdea(int, std::string const&)
{
	std::cout << "setIdea: No brain, no idea!" << std::endl;
}

/// @brief Attempts to get an idea at the given index.
/// @param index The position to retrieve the idea from (ignored).
/// @return A default message since base AAnimal has no ideas.
std::string	AAnimal::getIdea(int) const
{
	return ("getIdea: No brain, no idea!");
}
