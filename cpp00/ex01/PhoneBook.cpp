/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:47 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 18:47:43 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::init(void)
{
	std::cout << "AWESOME PHONEBOOK" << std::endl;
	this->index = 0;
	this->count = 0;
	return ;
}

void	PhoneBook::message_prompt(void)
{
	std::cout << "Please enter <ADD>, <SEARCH> or <EXIT>: ";
	return ;
}

void	PhoneBook::add(void)
{
	if (count == MAX)
		std::cout << "To do: Replace oldest contact" << std::endl;
	contact[index].create(&contact[index]);
	if (count < MAX)
		count++;
	if (index + 1 < MAX) //always replace the oldest modified index
		index++;
	else
		index = 0;
	return ;
}

void	PhoneBook::search(void)
{
	int	i;

	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "| Index | First name | Last name | Nickname |" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	i = 0;
	while (i < this->count)
	{
		std::cout << "|" << i + 1 << "|";
		std::cout << contact[i].get_first_name() << "|";
		std::cout << contact[i].get_last_name() << "|";
		std::cout << contact[i].get_nickname() << "|" << std::endl;
		std::cout << " -------------------------------------------" << std::endl;
		i++;
	}
	
	return ;
}
