/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:51:00 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/13 10:30:16 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materiasource.hpp"
#include "character.hpp"
#include "amateria.hpp"
#include "cure.hpp"
#include "ice.hpp"

int main()
{
	std::cout << "Subject test" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl << "Own tests" << std::endl;
	std::cout << std::endl << "Wrong type" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		AMateria* tmp;
		tmp = src->createMateria("fire");
		delete tmp;
		delete src;
	}
	std::cout << std::endl << "Unequip something what is not there" << std::endl;
	{
		ICharacter* me = new Character("Timmy");
		me->unequip(-1);
		me->unequip(0);
		me->unequip(10);
		delete me;
	}
	std::cout << std::endl << "Too many materials" << std::endl;
	{
		IMateriaSource* src;
		AMateria* 		tmp;
		int				i;

		src = new MateriaSource();
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		ICharacter* me = new Character("Timmy");
		i = 0;
		while (i < 5)
		{
			std::cout << "Added item nr " << i + 1 << " ";
			me->equip(tmp);
			std::cout << std::endl;
			i++;
		}
		std::cout << "Unequip two times the same one" << std::endl;
		me->unequip(0);
		me->unequip(0);
		me->unequip(1);
		delete me;
		delete src;
	}
	std::cout << "Deep copy Character" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* me = new Character("Test");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		Character*	you = new Character(*me);
		you->setName("Copy");
		std::cout << you->getName() << " ";
		you->use(0, *me);
		std::cout << me->getName() << " ";
		me->use(0, *you);
		me->unequip(0);
		std::cout << you->getName() << " ";
		you->use(0, *me);
		std::cout << me->getName() << " ";
		me->use(0, *you);

		delete you;
		delete me;
		delete src;
	}
	return (0);
}