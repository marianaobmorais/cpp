/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:12:34 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/03 19:15:44 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {}

Ice::Ice(Ice const& src) {}

Ice&	Ice::operator=(Ice const& rhs) {}

Ice::~Ice(void){}


AMateria*	Ice::clone() const //not sure about this override syntax
{}


void	Ice::use(ICharacter& target) //not sure about this override syntax
{}