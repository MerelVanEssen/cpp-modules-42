/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:37:38 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 08:22:05 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		std::cout << "Make a weapon and give it to Bob (HumanA)" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << RESET << "Attact with weapon, change weapon and attact again" << std::endl;
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << RESET << "Make a weapon, create Jim (HumanB)" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		std::cout << RESET << "Attact without a weapon:" << std::endl;
		jim.attack(); // without a weapon
		std::cout << RESET << "Give Jim the weapon and attack, change and attack again" << std::endl;
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}