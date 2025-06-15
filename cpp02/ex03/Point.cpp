/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:15 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/15 18:56:19 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/// @brief Default constructor. Initializes the point at coordinates (0, 0).
Point::Point(void) : x(0), y(0) {}

/// @brief Constructs a point with the given x and y coordinates.
/// @param x The x-coordinate.
/// @param y The y-coordinate.
Point::Point(float const x, float const y) : x(x), y(y) {}

/// @brief Copy constructor. Creates a copy of the given Point.
/// @param src The Point to copy.
Point::Point(Point const& src) : x(src.x), y(src.y) {}

/// @brief Copy assignment operator. No-op due to const attributes.
/// @param rhs The Point to assign from.
/// @return Reference to this Point.
Point&	Point::operator=(Point const& rhs)
{
	(void)rhs;
	return (*this);
}

/// @brief Returns the x-coordinate of the point.
/// @return A constant reference to the x-coordinate.
Fixed const&	Point::getX(void) const
{
	return (x);
}

/// @brief Returns the y-coordinate of the point.
/// @return A constant reference to the y-coordinate.
Fixed const&	Point::getY(void) const
{
	return (y);
}

/// @brief Destructor. Destroys the Point instance.
Point::~Point(void) {}
