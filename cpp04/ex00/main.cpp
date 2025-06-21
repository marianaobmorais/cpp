/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:01:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 09:22:29 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) 
{
	std::cout << "\n----Animal, Dog and Cat----" << std::endl;
	Animal const*		meta = new Animal();
	Animal const*		d = new Dog();
	Animal const*		c = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	meta->makeSound();
	d->makeSound(); 
	c->makeSound();
	
	std::cout << "\n----Wrong Animal and Wrong Cat----" << std::endl;
	WrongAnimal const*	wrongMeta = new WrongAnimal();
	WrongAnimal const*	wrongC = new WrongCat();
	
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongC->getType() << " " << std::endl;
	wrongMeta->makeSound();
	wrongC->makeSound();
	//delete!!!
	return (0);
}