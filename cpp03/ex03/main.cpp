/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:05:09 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 09:24:59 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "Test to see if ClapTrap is only made once" << std::endl;
	{
		DiamondTrap	diam("Diamondy");

		diam.attack("No one");
		diam.whoAmI();
	}
	std::cout << std::endl << RES "Same amount of points" << std::endl;
	{
		ScavTrap	scav("Scavy");
		FragTrap	frag("Fraggy");
		DiamondTrap	diam("Diamondy");
		
		std::cout << std::endl;
		diam.printPoints();

		std::cout << std::endl << RES "Hit points FragTrap (100):" << std::endl;
		frag.takeDamage(1);
		std::cout << std::endl << RES "Attack damage FragTrap(30):" << std::endl;
		frag.attack("Diamondy");

		std::cout << std::endl << RES "Same amount of energie points (50):" << std::endl;
		int	i;
		i = 0;
		while (i < 51)
		{
			scav.beRepaired(1);
			i++;
		}
	}
	std::cout << std::endl << RES "On the heap" << std::endl;
	{
		DiamondTrap*	diamonds;

		diamonds = new DiamondTrap("Heaper");
		diamonds->whoAmI();
		diamonds->attack("someone");
		diamonds->takeDamage(1);
		diamonds->beRepaired(1);
		delete diamonds;
	}
	return (0);
}