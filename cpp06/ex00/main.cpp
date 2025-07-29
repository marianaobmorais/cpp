/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:55:28 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/29 13:26:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "USAGE: ./converter <string>" << std::endl;
		return (1);
	}
	std::string	str(argv[1]);

	std::cout << "DEBUG: input str: [" << str << "], length: " << str.length() << "\n";
	for (size_t i = 0; i < str.length(); ++i)
	std::cout << "char[" << i << "] = '" << str[i] << "' (" << static_cast<int>(str[i]) << ")\n\n";

	ScalarConverter::convert(str);
	return (0);
}
