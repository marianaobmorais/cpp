/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:43:56 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/23 15:02:37 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

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
			if (phonebook.get_count() == MAX)
				phonebook.message_warning();
		}
		else
			break ;
	}
	return (0);
}
