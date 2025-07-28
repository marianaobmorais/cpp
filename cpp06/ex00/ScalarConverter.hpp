/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:27:04 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/28 18:41:44 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		// no public constructor because it is meant to work like a pure utility class
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& src);
		ScalarConverter&	operator=(ScalarConverter const& rhs);
		~ScalarConverter(void);

	public:
		static void			convert(std::string const& value);
};

#endif // SCALARCONVERTER_HPP