/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:51:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/10 21:58:00 by mariaoli         ###   ########.fr       */
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
		//canonical form

		Fixed(void);
		Fixed(Fixed const& src);
		Fixed&	operator=(Fixed const& rhs);
		~Fixed(void);

		//other constructors

		Fixed(int const n);
		Fixed(float const f);

		//accessors

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//conversion methods

		float	toFloat(void) const;
		int		toInt(void) const;

		//comparison operators

		bool	operator>(Fixed const& rhs) const;
		bool	operator<(Fixed const& rhs) const;
		bool	operator>=(Fixed const& rhs) const;
		bool	operator<=(Fixed const& rhs) const;
		bool	operator==(Fixed const& rhs) const;
		bool	operator!=(Fixed const& rhs) const;

		//arithmetic operators

		Fixed	operator+(Fixed const& rhs) const;
		Fixed	operator-(Fixed const& rhs) const;
		Fixed	operator*(Fixed const& rhs) const;
		Fixed	operator/(Fixed const& rhs) const;

		//pre / post increment and decrement

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		//static min / max methods

		static Fixed&		min(Fixed& lhs, Fixed& rhs);
		static Fixed const&	min(Fixed const& lhs, Fixed const& rhs);
		static Fixed&		max(Fixed& lhs, Fixed& rhs);
		static Fixed const&	max(Fixed const& lhs, Fixed const& rhs);
};

//<< operator overload

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif //FIXED_HPP