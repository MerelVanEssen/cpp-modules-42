/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:40:24 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 07:36:24 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie*	horde;
	int		i;
	int		j;
	int		size[] = {5, 2, 0, -1};

	j = 0;
	while (j < 4)
	{
		std::cout << "Size: " << size[j] << std::endl;
		horde = zombieHorde(size[j], "Zombiez");
		i = 0;
		while (i < size[j])
		{
			horde[i].announce();
			i++;
		}
		delete [] horde;
		j++;
	}
	return (0);
}