/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:45:46 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/02 18:17:20 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/// @brief Default constructor for Harl.
Harl::Harl(void) {}

/// @brief Destructor for Harl.
Harl::~Harl(void) {}


/// @brief Outputs a complaint message based on the specified log level.
/// @param level The log level string ("DEBUG", "INFO", "WARNING", or "ERROR").
/// @note Prints a default message if the level is unrecognized.
void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;
	int			index = -1;

	while (i < 4)
	{
		if (levels[i] == level)
		{
			index = i;
			break ;
		}
		i++;
	}
	switch (index)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

/// @brief Prints a debug-level complaint message.
void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!" << std::endl;
}

/// @brief Prints an info-level complaint message.
void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

/// @brief Prints a warning-level complaint message.
void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month." << std::endl;
}

/// @brief Prints an error-level complaint message.
void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
