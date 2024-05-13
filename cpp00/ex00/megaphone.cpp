/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:24:46 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 11:06:07 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		i = 0;
		while (argv[i])
		{
			for (char ch : (std::string) argv[i])
				std::cout << (char) std::toupper(ch);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

// ./megaphone "shhhhh... I think the students are asleep..."				->	SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."	->	DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// ./megaphone 																->	* LOUD AND UNBEARABLE FEEDBACK NOISE *