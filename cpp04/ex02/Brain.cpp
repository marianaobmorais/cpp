/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:38:41 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 19:25:22 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/// @brief Default constructor. Initializes a Brain object.
Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

/// @brief Copy constructor.
/// Copies all ideas from the source Brain.
/// @param src The Brain object to copy from.
Brain::Brain(Brain const& src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

/// @brief Copy assignment operator.
/// Copies all ideas from the right-hand side Brain.
/// @param rhs The Brain object to assign from.
/// @return Reference to this Brain.
Brain&	Brain::operator=(Brain const& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

/// @brief Destructor.
Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

/// @brief Returns the idea stored at the given index.
/// @param index The index of the idea to retrieve (0-99).
/// @return The idea string if index is valid, otherwise an error message.
std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	else
		return ("Invalid index to get idea");
}

/// @brief Sets the idea at the given index.
/// @param index The index to set the idea at (0-99).
/// @param idea The idea string to store.
/// @note Prints an error message if index is invalid.
void	Brain::setIdea(int index, std::string const& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
	else
		std::cout << "Invalid index to set idea" << std::endl;
}
