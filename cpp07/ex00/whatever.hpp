/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:20:13 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/12 13:48:27 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>
T	max(T const& valueA, T const& valueB)
{
	return ((valueA > valueB) ? valueA : valueB);
}

template<typename T>
T	min(T const& valueA, T const& valueB)
{
	return ((valueA < valueB) ?  valueA : valueB);
}

template<typename T>
void	swap(T& valueA, T& valueB)
{
	T	tmp;

	tmp = valueA;
	valueA = valueB;
	valueB = tmp;
}

#endif //WHATEVER_HPP