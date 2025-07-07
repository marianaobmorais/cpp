/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:13:18 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/07 13:07:22 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_TMPLT 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	templates[MAX_TMPLT];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& src);
		MateriaSource&	operator=(MateriaSource const& rhs);
		~MateriaSource(void);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif //MATERIASOURCE_HPP