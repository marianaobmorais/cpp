/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:29:18 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/04 16:50:59 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

/// @brief Checks if the given string represents a single non-digit character.
/// @param str Input string to check.
/// @return true if it's a single non-digit character, false otherwise.
static bool	isChar(std::string const& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

/// @brief Checks if the given string can be converted to a valid int.
/// @param str Input string to check.
/// @return true if it represents a valid int within INT_MIN and INT_MAX.
static bool	isInt(std::string const& str)
{
	char	*endPtr;
	long	n;

	n = std::strtol(str.c_str(), &endPtr, 10); // base 10 -> will only accept decimal notation
	if (*endPtr == '\0' && n >= INT_MIN && n <= INT_MAX)
		return (true);
	return (false);
}

/// @brief Checks if the string is a valid float (with 'f' suffix or special float literals).
/// @param str Input string to check.
/// @return true if it is a float representation, false otherwise.
static bool	isFloat(std::string const& str)
{
	char	*endPtr;;

	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
		return (true);
	std::strtof(str.c_str(), &endPtr);
	if (*endPtr == 'f' && *(endPtr + 1) == '\0')
		return (true);
	return (false);
}

/// @brief Checks if the string is a valid double.
/// @param str Input string to check.
/// @return true if it is a double representation, false otherwise
static bool	isDouble(std::string const& str)
{
	char*	endPtr;

	if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
		return (true);
	strtod(str.c_str(), &endPtr);
	if (*endPtr == '\0')
		return (true);
	return (false);
}

/// @brief Converts a character to all scalar types and prints the result.
/// @param c Character to convert.
static void	convertFromChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << '\n';
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: "<< static_cast<double>(c) << std::endl;
}

/// @brief Converts an integer to all scalar types and prints the result.
/// @param n Integer to convert.
static void	convertFromInt(int n)
{
	if (n >= 0 && n <= 127)
	{
		if (std::isprint(n))
			std::cout << "char: '" << static_cast<char>(n) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
	else
		std::cout << "char: impossible" << '\n';
	std::cout << "int: " << n << '\n';
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(n) << "f\n";
	std::cout << "double: "<< static_cast<double>(n) << std::endl;
}

/// @brief Converts a floating-point number to all scalar types and prints the result.
/// @param fd Double to convert.
static void	convertFromDecimal(double fd)
{
	int	tmp = static_cast<int>(fd);

	if (tmp >= 0 && tmp <= 127)
	{
		if (std::isprint(tmp))
			std::cout << "char: '" << static_cast<char>(fd) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
	else
		std::cout << "char: impossible\n";
	if (std::isinf(fd) || std::isnan(fd) || fd < static_cast<double>(INT_MIN) || fd > static_cast<double>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(fd) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(fd) << "f\n";
	std::cout << "double: " << fd << std::endl;
}

/// @brief Detects the scalar type represented by the string and prints its conversions.
/// @param str String representing a scalar value.
void	ScalarConverter::convert(std::string const& str)
{
	if (isChar(str))
		convertFromChar(str[0]);
	else if (isInt(str)) 
	{
		int	n = std::atoi(str.c_str());
		convertFromInt(n);
	}
	else if (isFloat(str))
	{
		std::string	tmp = str;
		tmp.erase(tmp.length() - 1);
		double		fd = std::strtod(tmp.c_str(), NULL);
		convertFromDecimal(fd);
	}
	else if (isDouble(str))
	{
		std::string	tmp = str;
		double		fd = std::strtod(tmp.c_str(), NULL);
		convertFromDecimal(fd);
	}
	else
		std::cout << "Error: invalid input" << std::endl;
}
