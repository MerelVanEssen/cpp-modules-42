/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:42:07 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/17 08:53:39 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	test_array_easyfind(void)
{
	std::array<int, 3>	test_array{1, 2, 3};

	std::cout << GRE "Array with 1, 2, 3 - looking for 3 and 4" RES << std::endl;
	try
	{
		std::cout << *easyFind(test_array, 3) << std::endl;
	}
	catch(const char *error)
	{
		std::cerr << RED << error << RES << std::endl;
	}	
	try
	{
		std::cout << *easyFind(test_array, 4) << std::endl;
	}
	catch(const char *error)
	{
		std::cerr << RED << error << RES << std::endl;
	}
}

void	test_vector_easyfind(void)
{
	std::vector<int>	test_vector {3, 6, 8};

	std::cout << GRE "Vector with 3, 6, 8 - looking for 3 and 4" RES << std::endl;
	try
	{
		std::cout << *easyFind(test_vector, 3) << std::endl;
	}
	catch(const char *error)
	{
		std::cerr << RED << error << RES << std::endl;
	}	
	try
	{
		std::cout << *easyFind(test_vector, 4) << std::endl;
	}
	catch(const char *error)
	{
		std::cerr << RED << error << RES << std::endl;
	}
}

void	test_list_easyfind(void)
{
	std::list<int>	test_list = {8, 5, 3};
	
	std::cout << GRE "List with 8, 5, 3 - looking for 5 and 4" RES << std::endl;
	try
	{
		std::cout << *easyFind(test_list, 5) << std::endl;
	}
	catch(const char *error)
	{
		std::cerr << RED << error << RES << std::endl;
	}	
	try
	{
		std::cout << *easyFind(test_list, 4) << std::endl;
	}
	catch(const char *error)
	{
		std::cerr << RED << error << RES << std::endl;
	}
}

void	test_empty_easyfind(void)
{
	std::list<int>	test_list = {};
	
	std::cout << GRE "Empthy list - looking for 5" RES << std::endl;
	{
		try
		{
			std::cout << *easyFind(test_list, 5) << std::endl;
		}
		catch(const char *error)
		{
			std::cerr << RED << error << RES << std::endl;
		}	
	}
}

int	main(void)
{
	test_array_easyfind();
	test_vector_easyfind();
	test_list_easyfind();
	test_empty_easyfind();
}