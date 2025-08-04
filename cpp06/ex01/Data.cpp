/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:30:23 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/04 16:51:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/// @brief Constructs a Data object with a name and an age.
/// @param newName The name to initialize the Data object with.
/// @param newAge The age to initialize the Data object with.
Data::Data(std::string const& newName, int newAge) : name(newName), age(newAge) {}

/// @brief Sets the age of the Data object.
/// @param newAge The new age to assign.
void	Data::setAge(int newAge)
{
	this->age = newAge;
}
