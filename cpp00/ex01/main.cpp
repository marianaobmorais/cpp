/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:43:56 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/21 19:27:24 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	Contact		contact;
	PhoneBook	phonebook;

	std::cout << "Awesome Phonebook" << std::endl;
	phonebook.message_prompt();

	
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