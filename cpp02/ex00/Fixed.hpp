/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:51:29 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/31 00:55:25 by mariaoli         ###   ########.fr       */
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
		Fixed(void);
		~Fixed(void);
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP