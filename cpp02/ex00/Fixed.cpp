/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:39:08 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/10 17:33:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/// @brief Default constructor. Initializes the fixed-point value to 0.
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

/// @brief Copy constructor.
/// @param src The Fixed object to copy from.
Fixed::Fixed(Fixed const& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/// @brief Copy assignment operator.
/// @param rhs The Fixed object to assign from.
/// @return Reference to the assigned Fixed object.
Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

/// @brief Destructor. Called when the object goes out of scope.
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/// @brief Gets the raw fixed-point value.
/// @return The internal fixed-point value.
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/// @brief Sets the raw fixed-point value.
/// @param raw The new value to assign to the fixed-point field.
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
