/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:44:58 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 18:44:13 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), dogBrain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& src) : Animal(src)
{
	this->dogBrain = new Brain(*src.dogBrain); //deep copy
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->dogBrain)
			delete(dogBrain);
		this->dogBrain = new Brain(*rhs.dogBrain); //deep copy
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete(this->dogBrain);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " says: woof woof" << std::endl;
}

void	Dog::setIdea(int index, std::string const& idea)
{
	this->dogBrain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return (this->dogBrain->getIdea(index));
}

Brain const*	Dog::getBrainPtr(void) const
{
	return (this->dogBrain);
}