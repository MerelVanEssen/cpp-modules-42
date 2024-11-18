/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:39:03 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/02 07:48:21 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "test.hpp"

void	test_int(void)
{
	int	intArray[] = {5, 3, 1, 7, 9};

	std::cout << GRE "Int array" RES << std::endl;
	::iter(intArray, sizeof(intArray) / sizeof(int), printArray);
}

void	test_string(void)
{
	std::string string = "String";

	std::cout << GRE "String array" RES << std::endl;
	::iter(&string[0], string.length(), printArray);
}

void	test_class(void)
{
	test	tester[5];
	int		i;

	std::cout << GRE "Class array" RES << std::endl;
	i = 0;
	while (i < 5)
	{
		tester[i].setNr(i);
		i++;
	}
	::iter(&tester[0], sizeof(tester) / sizeof(test), printArray);
}

void	empty_array(void)
{
	int	intArray[] = {};

	std::cout << GRE "Empty array" RES << std::endl;
	::iter(intArray, sizeof(intArray) / sizeof(int), printArray);
}

int	main(void)
{
	test_int();
	test_string();
	test_class();
	empty_array();
	return (0);
}