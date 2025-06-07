/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:51:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/07 11:15:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits;
	public:
		Fixed(void);							//canonical
		~Fixed(void);							//canonical
		Fixed(Fixed const& src);				//canonical
		Fixed&	operator=(Fixed const& rhs);	//canonical

		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP