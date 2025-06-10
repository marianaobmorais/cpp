/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:51:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/10 23:26:08 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_fixedPointValue;		 // raw storage
		static int const	_fractionalBits = 8;	// 2⁸ = 256
	public:
		Fixed(void);								//canonical form //default constructor
		Fixed(Fixed const& src);					//canonical form //copy constructor //creates new instance
		Fixed&	operator=(Fixed const& rhs);		//canonical form //copy assignment operator //updates the current instance
		~Fixed(void);								//canonical form //destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP