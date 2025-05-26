/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:59:11 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 18:07:48 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/// @brief Checks if a file stream is in a good state.
/// @param stream The input or output stream to check.
/// @return true if the stream is good, false otherwise.
bool	checkFileStream(std::ios &stream)
{
	if (!stream.good())
	{
		std::cout << "Error: " << std::strerror(errno) << std::endl;
		return (false); 
	}
	return (true);
}

/// @brief Replaces all occurrences of s1 with s2 in the input file and writes to the output file.
/// @param infile Input file stream to read from.
/// @param outfile Output file stream to write to.
/// @param s1 The substring to find and replace.
/// @param s2 The replacement substring.
void	replace(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2)
{
	std::string	line;
	while (std::getline(infile, line))
	{
		std::size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
}
