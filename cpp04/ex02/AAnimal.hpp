/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:07:19 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 20:16:38 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(AAnimal const& src);
		AAnimal&	operator=(AAnimal const& rhs);
		virtual ~AAnimal(void);

		virtual void	makeSound(void) const = 0; //pure virtual method
		std::string	getType(void) const;

		virtual void		setIdea(int index, std::string const& idea) = 0; //pure virtual method
		virtual std::string	getIdea(int index) const = 0; //pure virtual method
};

#endif //ANIMAL_HPP