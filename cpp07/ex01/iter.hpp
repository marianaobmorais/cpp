/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:05:25 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/12 18:40:47 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void	iter(T* array, std::size_t length, F function)
{
	for (std::size_t i = 0; i < length; i++)
		function(array[i]);
}

template<typename T>
void	ftPrint(T const& info)
{
	std::cout << info;
}

// template<typename T>
// void	ftChangeToA(T& info)
// {
// 	info = 'A';
// 	std::cout << info;
// }

#endif //ITER_HPP