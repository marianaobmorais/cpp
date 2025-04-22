/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:57 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 18:40:30 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_input(void)
{
	std::string	input; //= "";

	if (std::getline(std::cin, input))
		return (input);
	else
		std::exit(0); //add message?
}

void	Contact::init(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
	return ;
}

void	Contact::create(Contact *contact)
{
	this->init();
	std::cout << "First name: ";
	this->first_name = contact->get_input();
	std::cout << "Last name: ";
	this->last_name = contact->get_input();
	std::cout << "Nickname: ";
	this->nickname = contact->get_input();
	std::cout << "Phone number: ";
	this->nickname = contact->get_input();
	std::cout << "Darkest secret: ";
	this->nickname = contact->get_input();
	return ;
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
