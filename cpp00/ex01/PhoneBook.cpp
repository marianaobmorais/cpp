/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:47 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 17:20:59 by mariaoli         ###   ########.fr       */
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
	// std::string	input;

	// std::cout << "First name: " << std::endl;
	// std::getline(std::cin, input);
	return ;
}

void	PhoneBook::search(void)
{
	std::cout << "entered SEARCH" << std::endl;
	return ;
}
