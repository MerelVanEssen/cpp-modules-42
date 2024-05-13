/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:30 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 11:55:01 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	std::cout << "New and delete (reverse order)" << std::endl;
	{
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();	
		delete dog;
		delete cat;
	}
	std::cout << std::endl << "Deep copy test" << std::endl;
	{
		Dog	*doggy = new Dog();
		doggy->setIdea(0, "No idea");
		doggy->setIdea(1, "A tiny idea");
		doggy->setIdea(2, "A good idea");
		Dog *copyDog = new Dog(*doggy);
		std::cout << "Fir dog -> Idea 1: " << doggy->getIdea(0) << "\tIdea 2: " << doggy->getIdea(1) << "\tIdea 3: " << doggy->getIdea(2) << std::endl;
		std::cout << "Sec dog -> Idea 1: " << copyDog->getIdea(0) << "\tIdea 2: " << copyDog->getIdea(1) << "\tIdea 3: " << copyDog->getIdea(2) << std::endl;
		std::cout << YEL "Change first idea for the first dog" RES << std::endl;
		doggy->setIdea(0, "Smart idea");
		std::cout << "Fir dog -> Idea 1: " << doggy->getIdea(0) << "\tIdea 2: " << doggy->getIdea(1) << "\tIdea 3: " << doggy->getIdea(2) << std::endl;
		std::cout << "Sec dog -> Idea 1: " << copyDog->getIdea(0) << "\tIdea 2: " << copyDog->getIdea(1) << "\tIdea 3: " << copyDog->getIdea(2) << std::endl;
		delete doggy;
		delete copyDog;
	}
	std::cout << std::endl << "Test to paste a idea in the midle of the brain" << std::endl;
	{
		Brain	brain;

		brain.setIdea(5, "Look over there");
		std::cout << YEL "Idea\t" << brain.getIdea(5) << RES << std::endl;
	}
	std::cout << std::endl << "String with animals" << std::endl;
	{
		const Animal	*animals[4];
		int				i;

		i = 0;
		while (i < 4)
		{
			if (i < 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			i++;
		}
		i = 0;
		while (i < 4)
		{
			delete animals[i];
			i++;
		}
	}
	return (0);
}