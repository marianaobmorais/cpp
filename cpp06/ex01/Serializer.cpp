/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:32:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/04 16:52:46 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/// @brief Converts a pointer to a raw uintptr_t value for serialization.
/// @param ptr Pointer to a Data object.
/// @return The raw uintptr_t representation of the pointer.
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}


/// @brief Converts a raw uintptr_t value into a pointer to a Data object.
/// @param raw The raw uintptr_t value to convert.
/// @return The pointer to the Data object represented by the raw value.
Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}