/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:04:43 by mariaoli          #+#    #+#             */
/*   Updated: 2025/12/17 20:30:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const& src);
		Array&	operator=(Array const& rhs);
		~Array();

		T const&	operator[](unsigned int index) const;
		T&			operator[](unsigned int index);

		unsigned int	size(void) const;
};

#include "Array.tpp"

#endif //ARRAY_HPP