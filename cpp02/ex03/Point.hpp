/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:29:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/11 18:48:33 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& src);
		Point&	operator=(Point const& rhs);
		~Point(void);

		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif //POINT_HPP