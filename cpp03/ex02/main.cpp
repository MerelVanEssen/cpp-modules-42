/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:41:34 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 07:51:03 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "Test: Use own functions and the one from ClapTrap" << std::endl;
	{
		ClapTrap	clap("Clappy");
		ScavTrap	scav("Scavy");
		FragTrap	frag("Fraggy");

		clap.attack("Scavy");
		scav.takeDamage(1);
		scav.guardGate();
		frag.beRepaired(3);
		frag.highFivesGuys();
	}
	std::cout << std::endl << RES "Test to see how they can battle and die on the end" << std::endl;
	{
		ClapTrap	clap("Clappy");
		ScavTrap	scav("Scavy");
		FragTrap	frag("Fraggy");
		int			i;

		i = 0;
		frag.attack("Clappy");
		clap.takeDamage(30);
		while (i < 10)
		{
			scav.attack("Fraggy");
			frag.takeDamage(20);
			scav.guardGate();
			frag.attack("Scavy");
			scav.takeDamage(20);
			frag.beRepaired(10);
			frag.highFivesGuys();
			i++;
		}
	}
	return (0);
}
