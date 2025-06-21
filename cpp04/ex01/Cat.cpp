/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:25:24 by mariaoli          #+#    #+#             */
/*   Updated: 2025/06/21 18:44:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), catBrain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const& src) : Animal(src)
{
	this->catBrain = new Brain(*src.catBrain); //deep copy
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->catBrain)
			delete (this->catBrain);
		this->catBrain = new Brain(*rhs.catBrain); //deep copy
	}
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete(this->catBrain);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " says: meow meow" << std::endl;
}

void	Cat::setIdea(int index, std::string const& idea)
{
	this->catBrain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	return (this->catBrain->getIdea(index));
}

Brain const*	Cat::getBrainPtr(void) const
{
	return (this->catBrain);
}