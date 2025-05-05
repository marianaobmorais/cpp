/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:47 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/05 17:34:36 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

/// @brief Default constructor for the PhoneBook class.
PhoneBook::PhoneBook(void){}

/// @brief Destructor for the PhoneBook class.
PhoneBook::~PhoneBook(void){}

/// @brief Initializes the phonebook display and sets initial values.
void	PhoneBook::init(void)
{
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|             AWESOME PHONEBOOK             |" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	this->index = 0;
	this->count = 0;
	return ;
}

/// @brief Displays the prompt for user input.
void	PhoneBook::message_prompt(void)
{
	std::cout << "Please enter <ADD>, <SEARCH> or <EXIT>: ";
}

/// @brief Displays a warning when the phonebook is full.
void	PhoneBook::message_warning(void)
{
	std::cout << std::endl;
	std::cout << "Warning: Phonebook is full!" << std::endl;
	std::cout << "A new contact will replace the oldest one" << std::endl;
	std::cout << std::endl;
}

/// @brief Returns the number of contacts in the phonebook.
int	PhoneBook::get_count(void) const
{
	return (this->count);
}

/// @brief Adds a new contact to the phonebook.
/// @note Prompts the user for contact details. If the phonebook is full, it replaces the oldest contact.
void	PhoneBook::add(void)
{
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|                    ADD                    |" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	if (count == MAX)
		this->message_warning();
	contact[index].create(&contact[index]);
	if (count < MAX)
		count++;
	if (index + 1 < MAX)
		index++;
	else
		index = 0;
	return ;
}

/// @brief Allows the user to search for a contact by index and displays the contact's information.
/// @note Prompts the user to enter the index of the contact they want to view. If the index is valid, 
/// displays the contact's details; otherwise, an error message is shown, and the user is prompted again.
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
		std::cout << "Error: This index is not available. Try again" << std::endl;
		this->index_search();
	}
}

/// @brief Displays all contacts in the phonebook and prompts the user for a contact index to view.
/// @note If no contacts are available, shows a message indicating the phonebook is empty.
/// After displaying the list, the user can select an index to view the contact details.
void	PhoneBook::search(void)
{
	int			i;
	std::string	tmp;

	std::cout << std::left;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|                   SEARCH                  |" << std::endl;
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
		return ;
	}
	std::cout << std::right;
	i = 0;
	while (i < this->count)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncate(contact[i].get_first_name()) << "|";
		std::cout << std::setw(10) << truncate(contact[i].get_last_name()) << "|";
		std::cout << std::setw(10) << truncate(contact[i].get_nickname()) << "|" << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
		i++;
	}
	if (this->get_count() == MAX)
		this->message_warning();
	this->index_search();
}
