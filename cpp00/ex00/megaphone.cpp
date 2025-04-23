/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:24:16 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/23 13:55:34 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int i = 1;
		while (i < argc)
		{
			std::string arg(argv[i]);
			std::string::size_type j = 0;
			while (j < arg.length())
			{
				std::cout << static_cast<char>(std::toupper(arg[j]));
				j++;
			}
			i++;
			if (i < argc)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}
