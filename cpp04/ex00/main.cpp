/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:30 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 11:44:22 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "Type:\t" << j->getType() << " " << std::endl;
		std::cout << "Type:\t" << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl << "Tests with wrong animal and wrong cat:" << std::endl;
	{
		const WrongAnimal* animal = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout << "Type:\t\t" << cat->getType() << " " << std::endl;
		cat->makeSound();
		animal->makeSound();

		delete animal;
		delete cat;		
	}
	return (0);
}