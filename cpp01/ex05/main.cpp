/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:13:27 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/17 02:17:54 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR:" << std::endl;
	harl.complain("ERROR");
	return (0);
}
