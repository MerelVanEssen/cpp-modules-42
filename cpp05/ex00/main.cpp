/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:33 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/07/18 08:14:35 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test_too_low(void)
{
	Bureaucrat	paul("Paul", 148);

	try
	{
		while (paul.getGrade() < 152)
		{
			std::cout << YEL << paul << RES << std::endl;
			paul.setGrade(paul.getGrade() + 1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	test_too_high(void)
{
	Bureaucrat	marc("Marc", 3);

	try
	{
		while (marc.getGrade() > -2)
		{
			std::cout << YEL << marc << RES << std::endl;
			marc.setGrade(marc.getGrade() - 1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	test_wrong_init(void)
{
	std::cout << BLU "Bureaucrat made with -5" RES << std::endl;
	Bureaucrat	ad("Ad", -5);
	std::cout << YEL << ad << RES << std::endl;
	std::cout << std::endl;
	std::cout << BLU "Bureaucrat made with 155" RES << std::endl;
	Bureaucrat	dirk("Dirk", 155);
	std::cout << YEL << dirk << RES << std::endl;

}

void	test_cc_and_operator()
{
	std::cout << BLU "Copy construtor used" RES << std::endl;
	Bureaucrat	original_bc("Original", 5);
	Bureaucrat	copy_bc(original_bc);

	std::cout << YEL << original_bc << std::endl;
	std::cout << copy_bc << RES << std::endl;

	std::cout << BLU "operator= used" RES<< std::endl;
	Bureaucrat	different("Different", 10);
	std::cout << YEL << different << RES << std::endl;
	different = original_bc;
	std::cout << YEL << different << RES << std::endl;
}

int	main(void)
{
	test_too_low();
	std::cout << std::endl;
	test_too_high();
	std::cout << std::endl;
	test_wrong_init();
	std::cout << std::endl;
	test_cc_and_operator();
	return (0);
}