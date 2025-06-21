/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:31:49 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 18:42:20 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*catBrain;
	public:
		Cat(void);
		Cat(Cat const& src);
		Cat&	operator=(Cat const& rhs);
		~Cat(void);

		void			makeSound(void) const; //override

		void			setIdea(int index, std::string const& idea);  //overrride
		std::string		getIdea(int index) const;  //overrride
		Brain const*	getBrainPtr(void) const;
};

#endif // CAT_HPP