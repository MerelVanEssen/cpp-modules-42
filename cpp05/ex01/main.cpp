/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:48 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/13 10:37:21 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_signed(Form& form)
{
	Bureaucrat	marc("Marc", 5);

	try
	{
		std::cout << YEL << marc << std::endl;
		marc.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << BLU << marc.getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << RES << std::endl;
	}
}

void	test_not_signed(Form& form)
{
	Bureaucrat	paul("Paul", 45);

	try
	{
		std::cout << YEL << paul << std::endl;
		paul.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << BLU << paul.getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << RES << std::endl;
	}
}

void	test_copy_constructors(Form& form)
{
	Form	copy_form(form);

	std::cout << YEL << form << std::endl;
	std::cout << copy_form << RES << std::endl;

	Bureaucrat	original_bc("Original", 5);
	Bureaucrat	copy_bc(original_bc);

	std::cout << YEL << original_bc << std::endl;
	std::cout << copy_bc << RES << std::endl;
}

int	main(void)
{
	Form	form("Example", 30, 40);

	std::cout << std::endl;
	test_signed(form);
	std::cout << std::endl;
	test_not_signed(form);
	std::cout << std::endl;
	test_copy_constructors(form);
	return (0);
}
