/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:57 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/29 19:26:29 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

/// @brief Default constructor for the Contact class.
Contact::Contact(void){}

/// @brief Destructor for the Contact class.
Contact::~Contact(void){}

/// @brief Prompts the user for input and ensures it is not empty.
/// @param str Prompt message to display.
/// @return A non-empty user-provided string.
/// @note Terminates the program on EOF (Ctrl+D).
std::string	Contact::get_input(std::string str)
{
	std::string	input;

	while (std::getline(std::cin, input))
	{
		if (input.empty())
		{
			std::cout << "Error: Empty fields are not accepted" << std::endl;
			std::cout << str;
		}
		else
		{
			handle_whitespaces(input);
			return (input);
		}
	}
	std::exit(0);
}

/// @brief Prompts the user to enter an index and validates it as a digit.
/// @return A valid integer index entered by the user.
/// @note Terminates the program on EOF (Ctrl+D).
int	Contact::get_index(void)
{
	std::string			input;
	int					index;
	bool				check;

	while (std::getline(std::cin, input))
	{
		check = all_digits(input);
		std::istringstream	iss(input);
		if (input.empty() || !check || !(iss >> index))
		{
			std::cout << "Error: Only the index numbers are accepted" << std::endl;
			std::cout << "Enter index to display complete contact info: ";
			continue ;
		}
		else
			return (index);	
	}
	std::exit(0);
}

/// @brief Initializes a Contact object with user-provided values.
/// @param contact Pointer to another Contact object used to fetch inp
void	Contact::create(Contact *contact)
{
	std::cout << "First name: ";
	this->first_name = contact->get_input("First name: ");
	std::cout << "Last name: ";
	this->last_name = contact->get_input("Last name: ");
	std::cout << "Nickname: ";
	this->nickname = contact->get_input("Nickname: ");
	std::cout << "Phone number: ";
	this->phone_number = contact->get_input("Phone number: ");
	while (!all_digits(this->phone_number))
	{
		std::cout << "Error: Only numbers are accepted" << std::endl;
		std::cout << "Phone number: ";
		this->phone_number = contact->get_input("Phone number: ");
	}
	std::cout << "Darkest secret: ";
	this->darkest_secret = contact->get_input("Darkest secret: ");
}

/// @brief Returns the first name of the contact.
/// @return First name as a string.
std::string	Contact::get_first_name() const
{
	return (this->first_name);
}

/// @brief Returns the last name of the contact.
/// @return Last name as a string.
std::string	Contact::get_last_name() const
{
	return (this->last_name);
}

/// @brief Returns the nickname of the contact.
/// @return Nickname as a string.
std::string Contact::get_nickname() const
{
	return (this->nickname);
}

/// @brief Returns the phone number of the contact.
/// @return Phone number as a string.
std::string	Contact::get_phone_number() const
{
	return (this->phone_number);
}

/// @brief Returns the darkest secret of the contact.
/// @return Darkest secret as a string.
std::string Contact::get_darkest_secret() const
{
	return (this->darkest_secret);
}
