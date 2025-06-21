/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:50:34 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 17:31:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(Brain const& src);
		Brain&	operator=(Brain const& rhs);
		~Brain(void);

		void		setIdea(int index, std::string const& idea);
		std::string	getIdea(int index) const;
};

#endif //BRAIN_HPP