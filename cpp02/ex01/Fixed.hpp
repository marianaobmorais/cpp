/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:51:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/10 21:01:49 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static int const	_fractionalBits = 8;
	public:
		Fixed(void);							//canonical form //default constructor
		Fixed(Fixed const& src);				//canonical form //copy constructor //creates new instance
		Fixed&	operator=(Fixed const& rhs);	//canonical form //copy assignment operator //updates the current instance
		~Fixed(void);							//canonical form //destructor
		
		Fixed(int const n);
		Fixed(float const f);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif //FIXED_HPP