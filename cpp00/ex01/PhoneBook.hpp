/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:59:30 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/23 19:47:39 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip> //std::setw
#include <ios> //std::left
#include <string>
#include "Contact.hpp"

#define MAX 8

class PhoneBook
{
	private:
		Contact	contact[MAX];
		int		index;
		int		count;
	public:
		PhoneBook();
		~PhoneBook(void);
		void	init(void);
		void	message_prompt(void);
		void	message_warning(void);
		int		get_count(void);
		void	add(void);
		void	search(void);
		void	index_search(void);
};

#endif //PHONEBOOK_HPP