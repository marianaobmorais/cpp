/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:03:05 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/22 17:33:09 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <stdlib.h> //exit
class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_numer;
		std::string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		void		init(void);
		void		create(Contact *contact);
		std::string	get_input();
};

#endif //CONTACT_HPP