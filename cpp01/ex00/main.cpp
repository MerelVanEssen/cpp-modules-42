/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:15:57 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/07 07:19:50 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	functieToShowHeap(Zombie *four)
{
	four->announce();
	four->setName("ChangeFour");
}

static void	functieToShowStack(Zombie three)
{
	three.announce();
	three.setName("ChangeThree");
}

int	main(void)
{
	std::cout << "ONE (normal):" << std::endl;
	Zombie	one;
	one.randomChump("One");
	one.setName("ChangeOne");
	std::cout << BLUE "After changing name: " << one.getName() << std::endl << std::endl;
	
	std::cout << RESET "TWO (pointer):" << std::endl;
	Zombie	*two;
	two = Zombie::newZombie("Two");
	two->announce();
	two->setName("ChangeTwo");
	std::cout << BLUE "After changing name: " << two->getName() << std::endl;
	
	std::cout << std::endl;
	std::cout << RESET "THREE (Zombie destroyed outside scope):" << std::endl;
	Zombie	three;
	three.setName("Three");
	functieToShowStack(three);
	std::cout << BLUE "After changing name: " << three.getName() << std::endl;
	
	std::cout << std::endl << RESET "FOUR (pointer):" << std::endl;
	Zombie	*four;
	four = Zombie::newZombie("Four");

	functieToShowHeap(four);
	std::cout << BLUE "After changing name: " << four->getName() << std::endl;

	delete four;
	delete two;

	return (0);
}