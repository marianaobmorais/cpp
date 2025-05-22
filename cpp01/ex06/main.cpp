/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:41:19 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/22 16:12:26 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "USAGE: ./harlFilter <level>" << std::endl;
		return (1);
	}
	if (argc == 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		Harl		harl;
		std::string	str(argv[1]);

		harl.complain(str);
	}
	return (0);
}