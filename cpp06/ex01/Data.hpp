/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:47:07 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/01 12:14:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data
{
	std::string	name;
	int			age;

	Data(std::string const& newName, int newAge); //why is newName const&?
	void	setAge(int newAge);
};

#endif //DATA_HPP