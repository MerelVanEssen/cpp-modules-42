/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:07:46 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 07:40:41 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "Test to see the inheritens functions and attributes from ClapTrap" << std::endl;
	{
		ScavTrap	scav("Scavy");

		scav.guardGate();
		scav.attack("Trappy");
		scav.takeDamage(5);
		scav.beRepaired(3);
	}
	std::cout << std::endl << RES "Test to see how they can battle and die on the end" << std::endl;
	{
		ScavTrap	scav("Scavy");
		ScavTrap	trap("Trappy");
		int			i;

		i = 0;
		while (i < 10)
		{
			scav.attack("Trappy");
			trap.takeDamage(20);
			scav.guardGate();
			trap.attack("Scavy");
			scav.takeDamage(20);
			trap.beRepaired(10);
			trap.guardGate();
			i++;
		}
	}
	return (0);
}