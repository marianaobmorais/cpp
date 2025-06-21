/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:07:19 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 15:25:39 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(Animal const& src);
		Animal&	operator=(Animal const& rhs);
		virtual ~Animal(void); //virtual method asks for virtual destructor, only the base class destructor (Animal) would run — which could cause resource leaks or undefined behavior for derived classes.

		//Adding virtual keyword will make the resolution of the function call dynamic.
		//Dynamic dispatch means the resolution will be done during the execution (runtime resolution/runtime polymorphism), not during compiling (static binding: the base class method is called, even if the object is of the derived class)
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
};

#endif //ANIMAL_HPP