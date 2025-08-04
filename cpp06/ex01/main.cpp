/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:28:42 by mariaoli          #+#    #+#             */
/*   Updated: 2025/08/04 20:13:39 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data	person("Arthur", 42);
	Data*	personPtr = &person;

	std::cout << "\n[Original pointer]" << std::endl;
	std::cout << "Memory address: "<< personPtr << std::endl;
	std::cout << "Name: "<< person.name << std::endl;
	std::cout << "Age: "<< person.age << std::endl;

	uintptr_t	personSerialized = Serializer::serialize(personPtr);
	Data*		personDeserialized = Serializer::deserialize(personSerialized);

	std::cout << std::endl;
	std::cout << "[Serialized pointer]" << std::endl;
	std::cout << "Raw uintptr_t: " << personSerialized << std::endl;

	std::cout << std::endl;
	std::cout << "[Deserialized pointer]" << std::endl;
	std::cout << "Memory address: " << personDeserialized << std::endl;
	std::cout << "Name: " << personDeserialized->name << std::endl;
	std::cout << "Age: " << personDeserialized->age << std::endl;

	std::cout << std::endl;
	std::cout << "[Test: modify age in Deserialized pointer]" << std::endl;
	personPtr->setAge(24);
	std::cout << "Check Deserialized pointer's age: " << personDeserialized->age << std::endl;
	std::cout << "Check Original pointer's age: " << personPtr->age << std::endl;
	
	
	std::cout << std::endl;
	std::cout << "[Veredict]" << std::endl;
	if (personPtr == personDeserialized)
		std::cout << "Original pointer == Deserialized pointer" << std::endl;
	else
		std::cout << "Original pointer != Deserialized pointer" << std::endl;

	return (0);
}