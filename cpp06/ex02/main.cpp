/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:50:19 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/02 00:19:45 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	Base	*p = generate();
	std::cout << "[Identify by pointer]" << std::endl;
	identify(p);
	std::cout << "[Identify by reference]" << std::endl;
	identify(*p);
	delete (p);

	return (0);
}