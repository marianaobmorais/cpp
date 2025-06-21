/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:07:19 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 18:20:18 by mariaoli         ###   ########.fr       */
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
		virtual ~Animal(void);

		virtual void	makeSound(void) const;
		std::string	getType(void) const;

		virtual void		setIdea(int index, std::string const& idea); //overrride
		virtual std::string	getIdea(int index) const; //overrride
};

#endif //ANIMAL_HPP