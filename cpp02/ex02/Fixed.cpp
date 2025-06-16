/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:39:08 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/16 17:06:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/// @brief Default constructor. Initializes the fixed-point value to 0.
Fixed::Fixed(void) : _fixedPointValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

/// @brief Copy constructor.
/// @param src The Fixed object to copy from.
Fixed::Fixed(Fixed const& src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/// @brief Copy assignment operator.
/// @param rhs The Fixed object to assign from.
/// @return Reference to the assigned Fixed object.
Fixed&	Fixed::operator=(Fixed const& rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

/// @brief Destructor. Called when the object goes out of scope.
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

/// @brief Constructs a Fixed object from an integer.
/// @param n The integer value to convert.
Fixed::Fixed(int const n)
{
	//std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = n << _fractionalBits;
}

/// @brief Constructs a Fixed object from a float.
/// @param f The float value to convert.
Fixed::Fixed(float const f)
{
	//std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = round(f * (1 << _fractionalBits));
}

/// @brief Gets the raw fixed-point value.
/// @return The internal fixed-point value.
int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/// @brief Sets the raw fixed-point value.
/// @param raw The new value to assign to the fixed-point field.
void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

/// @brief Converts the fixed-point value to a float.
/// @return The float representation of the fixed-point value.
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

/// @brief Converts the fixed-point value to an integer.
/// @return The integer part of the fixed-point value.
int	Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

/// @brief Checks if this Fixed is greater than rhs.
/// @param rhs The right-hand Fixed to compare.
/// @return true if this is greater than rhs.
bool	Fixed::operator>(Fixed const& rhs) const
{
	return (this->_fixedPointValue > rhs._fixedPointValue);
}

/// @brief Checks if this Fixed is less than rhs.
/// @param rhs The right-hand Fixed to compare.
/// @return true if this is less than rhs.
bool	Fixed::operator<(Fixed const& rhs) const
{
	return (this->_fixedPointValue < rhs._fixedPointValue);
}

/// @brief Checks if this Fixed is greater than or equal to rhs.
/// @param rhs The right-hand Fixed to compare.
/// @return true if this is greater than or equal to rhs.
bool	Fixed::operator>=(Fixed const& rhs) const
{
	return (this->_fixedPointValue >= rhs._fixedPointValue);
}

/// @brief Checks if this Fixed is less than or equal to rhs.
/// @param rhs The right-hand Fixed to compare.
/// @return true if this is less than or equal to rhs.
bool	Fixed::operator<=(Fixed const& rhs) const
{
	return (this->_fixedPointValue <= rhs._fixedPointValue);
}

/// @brief Checks if this Fixed is equal to rhs.
/// @param rhs The right-hand Fixed to compare.
/// @return true if values are equal.
bool	Fixed::operator==(Fixed const& rhs) const
{
	return (this->_fixedPointValue == rhs._fixedPointValue);
}

/// @brief Checks if this Fixed is not equal to rhs.
/// @param rhs The right-hand Fixed to compare.
/// @return true if values are not equal.
bool	Fixed::operator!=(Fixed const& rhs) const
{
	return (this->_fixedPointValue != rhs._fixedPointValue);
}

/// @brief Adds two Fixed values.
/// @param rhs The right-hand Fixed.
/// @return A new Fixed representing the sum.
Fixed	Fixed::operator+(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

/// @brief Subtracts rhs from this Fixed.
/// @param rhs The right-hand Fixed.
/// @return A new Fixed representing the difference.
Fixed	Fixed::operator-(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

/// @brief Multiplies two Fixed values.
/// @param rhs The right-hand Fixed.
/// @return A new Fixed representing the product.
Fixed	Fixed::operator*(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

/// @brief Divides this Fixed by rhs.
/// @param rhs The right-hand Fixed.
/// @return A new Fixed representing the quotient.
Fixed	Fixed::operator/(Fixed const& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/// @brief Pre-increment operator.
/// @return A reference to the incremented Fixed.
Fixed&	Fixed::operator++(void)
{
	++_fixedPointValue;
	return (*this);
}

/// @brief Post-increment operator.
/// @return A copy of the Fixed before incrementing.
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++_fixedPointValue;
	return (temp);
}

/// @brief Pre-decrement operator.
/// @return A reference to the decremented Fixed.
Fixed&	Fixed::operator--(void)
{
	--_fixedPointValue;
	return (*this);
}

/// @brief Post-decrement operator.
/// @return A copy of the Fixed before decrementing.
Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--_fixedPointValue;
	return (temp);
}

/// @brief Returns the smaller of two Fixed references.
/// @param lhs Left-hand operand.
/// @param rhs Right-hand operand.
/// @return The smaller Fixed by reference.
Fixed&	Fixed::min(Fixed& lhs, Fixed &rhs)
{
	return ((lhs < rhs) ? lhs : rhs);
}

/// @brief Returns the smaller of two constant Fixed references.
/// @param lhs Left-hand operand.
/// @param rhs Right-hand operand.
/// @return The smaller Fixed by const reference.
Fixed const& Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
	return ((lhs < rhs) ? lhs : rhs);
}

/// @brief Returns the larger of two Fixed references.
/// @param lhs Left-hand operand.
/// @param rhs Right-hand operand.
/// @return The larger Fixed by reference.
Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	return ((lhs > rhs) ? lhs : rhs);
}

/// @brief Returns the larger of two constant Fixed references.
/// @param lhs Left-hand operand.
/// @param rhs Right-hand operand.
/// @return The larger Fixed by const reference.
Fixed const& Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
	return ((lhs > rhs) ? lhs : rhs);
}

/// @brief Overloads the << operator to output a Fixed object.
/// @param out The output stream.
/// @param fixed The Fixed object to output.
/// @return The output stream.
std::ostream& operator<<(std::ostream& out, Fixed const& fixed)
{
	out << fixed.toFloat();
	return (out);
}
