/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:12:48 by mariaoli          #+#    #+#             */
/*   Updated: 2025/12/20 15:50:04 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "[CHAR CONST]" << std::endl;
	char const	array1[] = {'c', 'o', 'n', 's', 't', ' ', 't', 'e', 's', 't'};
	iter(array1, 10, ftPrint<char>);
	std::cout << std::endl;

	std::cout << "\n[CHAR NON-CONST]" << std::endl;
	char	array2[] = {'t', 'e', 's', 't'};
	iter(array2, 4, ftPrint<char>);
	std::cout << std::endl;

	std::cout << "\n[INT NON-CONST]" << std::endl;
	int	array3[] = {1, 2, 3, 4};
	iter(array3, 4, ftPrint<int>);
	std::cout << std::endl;
	return (0);
}

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
// 	o << rhs.get();
// 	return o;
// }

// template< typename T >
// void print( T& x )
// {
// 	std::cout << x << std::endl;
// 	return;
// }

// int main() {
// 	const int tab[] = { 0, 1, 2, 3, 4 };
// 	Awesome tab2[5];

// 	iter( tab, 5, print<const int> );
// 	iter( tab2, 5, print<Awesome> );

// 	return 0;
// }