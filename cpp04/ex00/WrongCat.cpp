/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:25:24 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 19:21:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/// @brief Default constructor. Sets type to "WrongCat".
WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

/// @brief Copy constructor.
/// @param src The WrongCat object to copy from.
WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/// @brief Copy assignment operator.
/// @param rhs The WrongCat object to assign from.
/// @return Reference to this WrongCat.
WrongCat&	WrongCat::operator=(WrongCat const& rhs)
{
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	std::cout << "WrongCat copy assignment called" << std::endl;
	return (*this);
}

/// @brief Destructor.
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/// @brief Prints the sound the WrongCat makes.
void	WrongCat::makeSound(void) const
{
	std::cout << this->type << " says: meow meow" << std::endl;
}