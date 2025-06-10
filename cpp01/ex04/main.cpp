/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 02:06:18 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/09 16:38:25 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "USAGE: ./program <filename> <string_1> <string_2>" << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (s1.empty())
	{
		std::cout << "Error: string_1 cannot be empty" << std::endl;
		return (1);
	}
	std::ifstream	infile(filename.c_str());
	if (!checkFileStream(infile))
		return (1);
	std::string	newFilename = filename.append(".replace");
	std::ofstream outfile(newFilename.c_str());
	if (!checkFileStream(outfile))
		return (1);
	replace(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	return (0);
}
