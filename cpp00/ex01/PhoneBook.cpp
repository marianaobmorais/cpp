/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:58:47 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 12:38:53 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::message_prompt(void)
{
	std::cout << "Please enter <ADD>, <SEARCH> or <EXIT>:" << std::endl;
}

void	PhoneBook::add(void)
{
	std::cout << "entered ADD" << std::endl;
}

void	PhoneBook::search(void)
{
	std::cout << "entered SEARCH" << std::endl;
}
