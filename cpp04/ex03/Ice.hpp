/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:25:24 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/04 10:01:33 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const& src);
		Ice&	operator=(Ice const& rhs);
		~Ice(void);

		AMateria*	clone(void) const; //override
		void		use(ICharacter& target); //override
};

#endif //ICE_HPP