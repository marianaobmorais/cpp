/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:01:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/22 10:45:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) 
{
	std::cout << "\n----Animal, Dog and Cat construct----" << std::endl;
	Animal generic;
	Animal const*		meta = new Animal();
	Animal const*		d = new Dog(); //Dog is an Animal during the compilation
	Animal const*		c = new Cat(); //Cat is an Animal during the compilation
	Animal const&		b = Cat();

	std::cout << "\n----Animal, Dog and Cat test----" << std::endl;
	std::cout << "Animal is a: " << meta->getType() << " " << std::endl;
	std::cout << "Dog is a: " << d->getType() << " " << std::endl;
	std::cout << "Cat is a: " << c->getType() << " " << std::endl;
	generic.makeSound();
	meta->makeSound();
	d->makeSound(); 
	c->makeSound();
	b.makeSound();

	std::cout << "\n----Animal, Dog and Cat destruct----" << std::endl;
	delete(d);
	delete(c);
	delete(meta);
	
	std::cout << "\n----Wrong Animal and Wrong Cat construct----" << std::endl;
	WrongAnimal const*	wrongMeta = new WrongAnimal();
	WrongAnimal const*	wrongC = new WrongCat();

	std::cout << "\n----Wrong Animal and Wrong Cat test ----" << std::endl;
	std::cout << "WrongAnimal is a: " << wrongMeta->getType() << std::endl;
	std::cout << "WrongCat is a: " << wrongC->getType() << std::endl;
	wrongMeta->makeSound();
	wrongC->makeSound();

	std::cout << "\n----Wrong Animal and Wrong Cat destruct----" << std::endl;
	delete(wrongMeta);
	delete(wrongC);

	std::cout << "\n----Object slicing----" << std::endl;
	Animal const	a = Dog();
	a.makeSound();

	std::cout << "\n----Destruct stack-allocated objects----" << std::endl;

	return (0);
}