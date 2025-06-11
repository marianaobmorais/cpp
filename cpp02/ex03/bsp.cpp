/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:57:08 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/11 18:25:57 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point const& a, Point const& b, Point const& c)
{
	Fixed	term1 = a.getX() * (b.getY() - c.getY());
	Fixed	term2 = b.getX() * (c.getY() - a.getY());
	Fixed	term3 = c.getX() *(a.getY() - b.getY());
	Fixed	area = term1 + term2 + term3;

	if (area < 0)
		area = area * -1;
	return (area/Fixed(2));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea = area(a, b, c);
	Fixed	areaPBC = area(point, b, c);
	Fixed	areaAPC = area(a, point, c);
	Fixed	areaABP = area(a, b, point);
	Fixed	sum = areaPBC + areaAPC + areaABP;

	return (totalArea == sum);
}
