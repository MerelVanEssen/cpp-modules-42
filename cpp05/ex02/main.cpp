/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:04 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 10:28:07 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test(Bureaucrat& paul)
{
	bool	executed;
	AForm	*form;

	executed = false;
	form = new PresidentialPardonForm("home");
	try
	{
		form->beSigned(paul);
		executed = paul.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	delete form;
	if (executed == false)
	{
		form = new RobotomyRequestForm("work");
		try
		{
			form->beSigned(paul);
			executed = paul.executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RES << std::endl;
		}
		delete form;
	}
	if (executed == false)
	{
		form = new ShrubberyCreationForm("school");
		try
		{
			form->beSigned(paul);
			executed = paul.executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << YEL "Grade doesn't fit for all the forms" RES << std::endl;
		}
		delete form;
	}
}

int	main(void)
{
	std::cout << "Test for PresidentialPardonForm" << std::endl;
	{
		Bureaucrat	paul("Paul", 5);

		test(paul);
	}
	std::cout << std::endl;
	std::cout << "Test for RobotomyRequestForm" << std::endl;
	{
		Bureaucrat	paul("Paul", 30);

		test(paul);
	}
	std::cout << std::endl;
	std::cout << "Test for ShrubberyCreationForm" << std::endl;
	{
		Bureaucrat	paul("Paul", 60);

		test(paul);
	}
	std::cout << std::endl;
	std::cout << "Test with a grade that is too low for all forms" << std::endl;
	{
		Bureaucrat	paul("Paul", 150);

		test(paul);
	}
	std::cout << std::endl;
	std::cout << "Test with a grade that is not valid, correction is applied" << std::endl;
	{
		Bureaucrat	paul("Paul", -1);

		test(paul);
	}
	return (0);
}
