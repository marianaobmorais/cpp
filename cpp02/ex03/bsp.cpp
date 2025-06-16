/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:57:08 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/16 03:33:40 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/// @brief Computes the absolute value of the area of a triangle using the determinant method.
/// @param a First vertex of the triangle.
/// @param b Second vertex of the triangle.
/// @param c Third vertex of the triangle.
/// @return The area as a Fixed-point number.
Fixed	area(Point const& a, Point const& b, Point const& c)
{
	Fixed	term1 = a.getX() * (b.getY() - c.getY());
	Fixed	term2 = b.getX() * (c.getY() - a.getY());
	Fixed	term3 = c.getX() *(a.getY() - b.getY());
	Fixed	area = term1 + term2 + term3;

	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area / Fixed(2));
}

/// @brief Checks if a point lies inside a triangle using area comparison.
/// @param a First vertex of the triangle.
/// @param b Second vertex of the triangle.
/// @param c Third vertex of the triangle.
/// @param point The point to check.
/// @return true if the point lies strictly inside the triangle (not on the edge).
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed		totalArea = area(a, b, c);
	Fixed		areaPBC = area(point, b, c);
	Fixed		areaAPC = area(a, point, c);
	Fixed		areaABP = area(a, b, point);
	Fixed		sum = areaPBC + areaAPC + areaABP;
	Fixed		diff = totalArea - sum;
	Fixed const	epsilon(0.004f);

	if (diff < Fixed(0))
		diff = diff * Fixed(-1);
	if (areaPBC > Fixed(0) && areaAPC > Fixed(0) && areaABP > Fixed(0) && diff < epsilon)
		return (true);
	return (false);
}
