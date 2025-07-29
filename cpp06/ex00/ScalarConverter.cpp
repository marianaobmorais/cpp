/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:29:18 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/29 12:55:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cfloat>

static bool	isChar(std::string const& str)
{
	//edge cases?
	if (str.length() == 1 && std::isprint(str[0]) && std::isalpha(str[0]))
		return (true);
	return (false);
}

static bool	isInt(std::string const& str)
{
	std::string::size_type	idx;

	try
	{
		std::stoi(str, &idx, 10); // base 10 -> will only accept decimal notation
		if (idx == str.length())
			return (true);
	}
	catch (std::exception const& e)
	{
		return (false);
	}
	return (false);
}

static bool	isFloat(std::string const& str)
{
	std::string::size_type	idx;

	if (str == "nanf" || str == "-inff" || str == "+inff")
		return (true);
	try
	{
		std::stof(str, &idx);
		if ((idx + 1 == str.length() && str[idx] == 'f'))
			return (true);
	}
	catch (std::exception const& e)
	{
		return (false);
	}
	return (false);
}

static bool	isDouble(std::string const& str)
{
	std::string::size_type	idx;

	if (str == "nan" || str == "-inf" || str == "+inf")
		return (true);
	try
	{
		std::stod(str, &idx);
		if (str.length() == idx)
			return (true);
	}
	catch (std::exception const& e)
	{
		return (false);
	}
	return (false);
}

static void	convertFromChar(char c)
{
	std::cout << "Char: " << c << '\n';
	std::cout << "Int: " << static_cast<int>(c) << '\n';
	std::cout << "Float: " << static_cast<float>(c) << 'f\n';
	std::cout << "Double: "<< static_cast<double>(c) << std::endl;
}

void	ScalarConverter::convert(std::string const& str)
{
	//validate input
	if (str.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return ;
	}
	// if (!std::isprint(str[0]))
	// {
	// 	std::cout << "Error: non-displayable char" << std::endl;
	// 	return ;
	// }
	if (isChar(str))
	{
		convertFromChar(str[0]);
	}
	else if (isInt(str))
	{
		;
	}
	else if (isFloat(str))
	{
		;
	}
	else if (isDouble(str))
	{
		;
	}
}
