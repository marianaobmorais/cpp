/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:17:15 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/07 14:57:41 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MAX_TMPLT; i++)
		templates[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	for (int i = 0; i < MAX_TMPLT; i++)
	{
		if (src.templates[i])
			this->templates[i] = src.templates[i]->clone();
		else
			this->templates[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < MAX_TMPLT; i++)
		{
			if (this->templates[i])
				delete this->templates[i];
			if (rhs.templates[i])
				this->templates[i] = rhs.templates[i]->clone();
			else
				this->templates[i] = NULL;
		}
	}
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MAX_TMPLT; i++)
		delete templates[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < MAX_TMPLT; i++)
		{
			if (!templates[i])
			{
				templates[i] = m->clone(); //deep copy
				std::cout << "Learned materia of type " << m->getType() << std::endl;
				return ;
			}
		}
		std::cout << "Cannot learn more: MateriaSource is full" << std::endl;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_TMPLT; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
		{
			std::cout << "Created materia of type " << type << std::endl;
			return (templates[i]->clone());
		}
	}
	std::cout << "Materia of type " << type << " not found: cannot be created" << std::endl;
	return (NULL);
}
