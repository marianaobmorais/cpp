/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:57 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/29 21:27:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

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
			return (input);
	}
	std::exit(0);
}

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

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}
