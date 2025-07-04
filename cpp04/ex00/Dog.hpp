/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:20:58 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 15:05:12 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const& src);
		Dog&	operator=(Dog const& rhs);
		~Dog(void);

		void	makeSound(void) const; //override
};

#endif //DOG_HPP