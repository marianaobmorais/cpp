/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:53:17 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/04 10:02:09 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const& src);
		Cure&	operator=(Cure const& rhs);
		~Cure(void);

		AMateria*	clone(void) const; //override
		void		use(ICharacter& target);
};

#endif //CURE_HPP