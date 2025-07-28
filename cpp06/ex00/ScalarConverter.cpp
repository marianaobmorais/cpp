/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:29:18 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/28 19:46:44 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>

static bool	isChar(std::string const& value)
{
	//edge cases?
	if (value.length() == 1 && std::isprint(value[0]) && std::isalpha(value[0]))
		return (true);
	return (false);
}

static bool	isInt(std::string const& value)
{
	size_t	idx;
	long	n = std::stol(value, &idx, 10); // base 10 = will only accept decimal notation

	if (!errno && idx == value.length() && n >= INT_MIN && n <= INT_MAX)
		return (true);
	return (false);
}

void	ScalarConverter::convert(std::string const& value)
{
	//validate input
	if (value.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return ;
	}
	if (isChar(value) || isInt(value))
	{
		//later
	}
	
	//float

	//double
	
}
