/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:47 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/23 12:59:04 by mariaoli         ###   ########.fr       */
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
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|             AWESOME PHONEBOOK             |" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	this->index = 0;
	this->count = 0;
	return ;
}

void	PhoneBook::message_prompt(void)
{
	std::cout << "Please enter <ADD>, <SEARCH> or <EXIT>: ";
	return ;
}

void	PhoneBook::message_warning(void)
{
	std::cout << std::endl;
	std::cout << "Warning: Phonebook is full!" << std::endl;
	std::cout << "The new contact will replace the oldest one" << std::endl;
	std::cout << std::endl;
}

int	PhoneBook::get_count(void)
{
	return (this->count);
}

void	PhoneBook::add(void)
{
	if (count == MAX)
		this->message_warning();
	contact[index].create(&contact[index]);
	if (count < MAX)
		count++;
	if (index + 1 < MAX) //always replace the oldest modified index
		index++;
	else
		index = 0;
	return ;
}

void	PhoneBook::index_search(void)
{
	int	index;

	std::cout << "Enter index of the entry to display contact info: ";
	index = contact->get_index();
	if (index > 0 && index <= this->count)
	{
		std::cout << "Selected index: " << index << std::endl;
		std::cout << "First name: ";
		std::cout << contact[index - 1].get_first_name() << std::endl;
		std::cout << "Last name: ";
		std::cout << contact[index - 1].get_last_name() << std::endl;
		std::cout << "Nickname: ";
		std::cout << contact[index - 1].get_nickname() << std::endl;
		std::cout << "Phone number: ";
		std::cout << contact[index - 1].get_phone_number() << std::endl;
		std::cout << "Darkest secret: ";
		std::cout << contact[index - 1].get_darkest_secret() << std::endl;
	}
	else
	{
		std::cout << "Error: this index is not available. Try again" << std::endl;
		this->index_search();
	}
	return ;
}

void	PhoneBook::search(void)
{
	int	i;

	std::cout << std::left;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
 	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	if (count == 0)
	{
		std::cout << "|           CONTACT LIST IS EMPTY           |" << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
	}
	std::cout << std::right;
	i = 0;
	while (i < this->count)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << contact[i].get_first_name() << "|";
		std::cout << std::setw(10) << contact[i].get_last_name() << "|";
		std::cout << std::setw(10) << contact[i].get_nickname() << "|" << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
		i++;
	}
	this->index_search();
	return ;
}
