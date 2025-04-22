/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:43:56 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 12:42:53 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	input;

	std::cout << "Awesome Phonebook" << std::endl;
	while (input.compare("EXIT") != 0)
	{
		phonebook.message_prompt();
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			phonebook.add();
		if (input.compare("SEARCH") == 0)
			phonebook.search();
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