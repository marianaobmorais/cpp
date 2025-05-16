/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 02:06:18 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/16 22:14:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "USAGE: ./program <filename> <string_1> <string_2>" << std::endl;
		return (1);
	}
	else
	{
		std::string filename(argv[1]); //check if the file is valid
		std::string s1(argv[2]);
		std::string s2(argv[3]);

		std::ifstream	infile(filename.c_str());
		if (!infile.is_open())
		{
			std::cout << "Error" << std::endl;
			return (1);
		}

		std::string	newFilename = filename.append(".replace");
		std::ofstream outfile(newFilename.c_str());
		if (!outfile.is_open())
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		else
		{
			std::string	line;
			while (std::getline(infile, line))
			{
				std::size_t	pos = line.find(s1, 0);
				while (pos != std::string::npos) //found match
				{
					line.erase(pos, s1.length());
					line.insert(pos, s2);
					pos = line.find(s1, pos);
				}
				outfile << line << std::endl;
			}
			infile.close();
			outfile.close();
		}
	}
	return (0);
}