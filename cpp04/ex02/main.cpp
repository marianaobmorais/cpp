/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:01:51 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/22 01:24:42 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

int	main(void)
{
	// std::cout << "\n----Wrong test----" << std::endl;
	// AAnimal a;

	std::cout << "\n----Basic test----" << std::endl;
	AAnimal const* d = new Dog();
	AAnimal const* c = new Cat();

	std::cout << "\n----Destruct heap allocated objects----" << std::endl;
	delete(d);
	delete(c);

	std::cout << "\n----Array test----" << std::endl;
	int const	arraySize = 4;
	AAnimal const* animal[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			std::cout << i << std::endl;
			animal[i] = new Dog();
		}
		else
		{
			std::cout << i << std::endl;
			animal[i] = new Cat();
		}
	}

	std::cout << "\n----Make sound test----" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << i << std::endl;
		animal[i]->makeSound();
	}

	std::cout << "\n----Destruct array----" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << i << std::endl;
		delete(animal[i]);
	}

	std::cout << "\n----Deep copy test----" << std::endl;
	Cat	grumpy;
	grumpy.setIdea(0, "Frown at people");
	Cat	grumpyCopy(grumpy);
	std::cout << "***Original idea: " << grumpy.getIdea(0) << " -> " << grumpy.getBrainPtr() << std::endl;
	std::cout << "***Copy idea: " << grumpyCopy.getIdea(0) << " -> " << grumpyCopy.getBrainPtr() << std::endl;
	grumpyCopy.setIdea(0, "Hiss at people");
	std::cout << "***Modified copy idea: " << grumpyCopy.getIdea(0) << grumpyCopy.getBrainPtr() << std::endl;
	std::cout << "***Original idea: " << grumpy.getIdea(0) << " -> " << grumpy.getBrainPtr() << std::endl;

	std::cout << "\n----A bit busy mind test----" << std::endl;
	Dog	milo;
	for (int i = 0; i < 10; i++)
		milo.setIdea(i, "Squirrel!");
	for(int i = 0; i < 10; i++)
		std::cout << "Milo's idea " << i <<": " << milo.getIdea(i) << std::endl;

	std::cout << "\n----Destruct stack-allocated objects----" << std::endl;

	return (0);
}
