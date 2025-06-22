/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:25:24 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/22 10:30:34 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/// @brief Default constructor for Cat. Initializes type and allocates new Brain.
Cat::Cat(void) : AAnimal(), catBrain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/// @brief Copy constructor for Cat. Performs deep copy of Brain.
/// @param src The Cat object to copy from.
Cat::Cat(Cat const& src) : AAnimal(src), catBrain(new Brain(*src.catBrain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/// @brief Copy assignment operator for Cat. Deletes old Brain and deep copies new Brain.
/// @param rhs The Cat object to assign from.
/// @return Reference to this Cat object.
Cat&	Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		if (this->catBrain)
			delete (this->catBrain);
		this->catBrain = new Brain(*rhs.catBrain); //deep copy
	}
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

/// @brief Destructor for Cat. Deletes Brain to prevent memory leaks.
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete(this->catBrain);
}

/// @brief Makes the Cat sound.
void	Cat::makeSound(void) const
{
	std::cout << this->type << " says: meow meow" << std::endl;
}

/// @brief Sets an idea in the Cat's Brain at the specified index.
/// @param index The index to set the idea at.
/// @param idea The idea string to store.
void	Cat::setIdea(int index, std::string const& idea)
{
	this->catBrain->setIdea(index, idea);
}

/// @brief Retrieves an idea from the Cat's Brain at the specified index.
/// @param index The index to retrieve the idea from.
/// @return The idea string stored at the index.
std::string	Cat::getIdea(int index) const
{
	return (this->catBrain->getIdea(index));
}

/// @brief Returns a pointer to the Cat's Brain.
/// @return Const pointer to the Brain object.
Brain const*	Cat::getBrainPtr(void) const
{
	return (this->catBrain);
}