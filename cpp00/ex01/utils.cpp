/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:02:16 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/30 18:30:46 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/// @brief Checks if a string contains only digits.
/// @param str The string to check.
/// @return True if the string contains only digits, false otherwise.
bool	all_digits(const std::string &str)
{
	std::string::size_type	i;

	i = 0;
	if (str.empty())
		return (false);
	while (i < str.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	return (true);
}

/// @brief Truncates a string to a maximum length of 10 characters.
/// @param str The string to truncate.
/// @return The truncated string, ending with a dot (.) if it exceeds 10 characters, or the original string if it doesn't.
std::string	truncate(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
