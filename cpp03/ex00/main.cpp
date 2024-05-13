/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:07:46 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 07:27:48 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "Test to see how the points work" << std::endl;
	{
		ClapTrap	clap("Clappy");
		ClapTrap	trap("Trappy");
		int			actions;

		actions = 0;
		while (actions < 10)
		{
			clap.attack("Trappy");
			trap.takeDamage(2);
			trap.attack("Clappy");
			clap.takeDamage(1);
			trap.beRepaired(1);
			actions++;
		}
	}
	std::cout << RES "Default ClapTrap" << std::endl;
	{
		ClapTrap	someone;
		
		someone.takeDamage(2);
	}
	std::cout << RES "Array ClapTraps" << std::endl;
	{
		ClapTrap	*array[3];
		int			i;

		i = 0;
		while (i < 3)
		{
			array[i] = new ClapTrap("ArrayClap");
			i++;
		}
		i = 0;
		while (i < 3)
		{
			array[i]->takeDamage(2);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			delete array[i];
			i++;
		}
	}
	return (0);
}
