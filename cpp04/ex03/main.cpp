/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:24:10 by mariaoli          #+#    #+#             */
/*   Updated: 2025/07/07 15:00:35 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n--------Basic tests--------" << std::endl;
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n--------Destruct--------" << std::endl;
	delete bob;
	delete me;
	delete src;

	std::cout << "\n--------Materia learning overflow--------" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());

	std::cout << "\n--------Materia equipping tests--------" << std::endl;
	ICharacter*	me2 = new Character("me2");
	AMateria*	tmp2;
	tmp2 = src2->createMateria("invalid");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);

	std::cout << "\n--------Destruct--------" << std::endl;
	delete me2;
	delete src2;
	return (0);
}
