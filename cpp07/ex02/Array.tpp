/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:14:43 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/12 22:43:27 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(Array<T> const& src) : _elements(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < src._size; i++)
		this->_elements[i] = src._elements[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const& rhs)
{
	if (this != &rhs)
	{
		if (this->_elements)
			delete[] (this->_elements);
		this->_size = rhs._size;
		this->_elements = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_elements[i] = rhs._elements[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] (this->_elements);
}

template<typename T>
T const&	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return (this->_elements[index]);
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return (this->_elements[index]);
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}
