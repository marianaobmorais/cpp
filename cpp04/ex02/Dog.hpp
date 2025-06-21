/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:20:58 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 20:19:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*dogBrain;
	public:
		Dog(void);
		Dog(Dog const& src);
		Dog&	operator=(Dog const& rhs);
		~Dog(void);

		void	makeSound(void) const; //override

		void			setIdea(int index, std::string const& idea);
		std::string		getIdea(int index) const;
		Brain const*	getBrainPtr(void) const;

};

#endif //DOG_HPP