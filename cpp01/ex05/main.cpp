/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:32:46 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/06 12:54:02 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	input;
	Harl		harl;
	
	if (argc != 2)
	{
		std::cout << "Not the right arguments" << std::endl;
		return (1);
	}
	input = argv[1];
	if (input.empty())
	{
		std::cout << "Empty input" << std::endl;
		return (1);
	}
	harl.complain(input);
	return (0);
}