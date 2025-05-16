/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:59:11 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/17 00:08:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	checkFileStream(std::ios &stream)
{
	if (!stream.good())
	{
		std::cout << "Error: " << std::strerror(errno) << std::endl;
		return (false); 
	}
	return (true);
}

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
