/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:40 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/04 16:44:47 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

struct Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const& src);
		Serializer&	operator=(Serializer const& rhs);
		~Serializer(void);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif //SERIALIZER_HPP