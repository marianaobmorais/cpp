/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:43:56 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 18:21:24 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input; // = "";

	phonebook.init();
	while (true)
	{
		phonebook.message_prompt();
		if (std::getline(std::cin, input))
		{
			if (!input.compare("EXIT"))
				break ;
			if (!input.compare("ADD"))
				phonebook.add();
			if (!input.compare("SEARCH"))
				phonebook.search();
			// else //any other input is ignored
			// 	std::cout << "Invalid input" << std::endl;
		}
		else
			break ;
	}
	return (0);
}


// int	main(void)
// {
// 	char	buff[1024]; //check limit?

// 	std::cout << "Welcome to My Awesome Phonebook!" << std::endl;
// 	std::cout << "Please enter one of the three commands:" << std::endl;
// 	std::cout << "<ADD> <SEARCH> <EXIT>: " << std::endl;
// 	std::cin >> buff;
// 	//while (buff.compare("EXIT") != 0)
// 	// {
// 	// 	std::cin >> buff;
// 	// }
// 	std::cout << "You entered: [" << buff << "]" << std::endl;
// 	return (0);
// }