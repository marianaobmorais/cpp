/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:56:25 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/04 10:01:51 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(AMateria const& src);
		AMateria&	operator=(AMateria const& rhs);
		virtual ~AMateria(void);

		std::string const&	getType(void) const;

		virtual AMateria*	clone(void) const = 0; //clone is pure virtual because every derived class must implement how to clone itself
		virtual void		use(ICharacter& target); //use has a default behavior, but can be overrinden if needed
};

#endif //AMATERIA_HPP