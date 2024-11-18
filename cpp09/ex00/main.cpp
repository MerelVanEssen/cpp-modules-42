/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:42:23 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/13 13:25:09 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	be;

	if (argc != 2 || !argv[1])
	{
		std::cerr << RED "Error: could not open file." RES << std::endl;
		return (1);
	}
	try
	{
		be.loadData();
		be.calculateExchange(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " << e.what() << RES << std::endl;
	}
	BitcoinExchange	copy(be);
	BitcoinExchange	another = copy;
	return (0);
}
