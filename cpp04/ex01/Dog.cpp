/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:44:58 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/22 10:27:57 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/// @brief Default constructor for Dog. Initializes type and alloDoges new Brain.
Dog::Dog(void) : Animal(), dogBrain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/// @brief Copy constructor for Dog. Performs deep copy of Brain.
/// @param src The Dog object to copy from.
Dog::Dog(Dog const& src) : Animal(src), dogBrain(new Brain(*src.dogBrain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/// @brief Copy assignment operator for Dog. Deletes old Brain and deep copies new Brain.
/// @param rhs The Dog object to assign from.
/// @return Reference to this Dog object.
Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->dogBrain)
			delete(dogBrain);
		this->dogBrain = new Brain(*rhs.dogBrain); //deep copy
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

/// @brief Destructor for Dog. Deletes Brain to prevent memory leaks.
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete(this->dogBrain);
}

/// @brief Makes the Dog sound.
void	Dog::makeSound(void) const
{
	std::cout << this->type << " says: woof woof" << std::endl;
}

/// @brief Sets an idea in the Dog's Brain at the specified index.
/// @param index The index to set the idea at.
/// @param idea The idea string to store.
void	Dog::setIdea(int index, std::string const& idea)
{
	this->dogBrain->setIdea(index, idea);
}

/// @brief Retrieves an idea from the Dog's Brain at the specified index.
/// @param index The index to retrieve the idea from.
/// @return The idea string stored at the index.
std::string	Dog::getIdea(int index) const
{
	return (this->dogBrain->getIdea(index));
}

/// @brief Returns a pointer to the Dog's Brain.
/// @return Const pointer to the Brain object.
Brain const*	Dog::getBrainPtr(void) const
{
	return (this->dogBrain);
}