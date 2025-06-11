/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:50:20 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/11 18:59:41 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(0.0f, 10.0f);
	Point	p1(3.0f, 3.0f);
	Point	p2(10.0f, 10.0f);
	Point	p3(5.0f, 0.0f);

	std::cout << "p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle" << std::endl;
	std::cout << "p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle" << std::endl;
	return (0);
}
