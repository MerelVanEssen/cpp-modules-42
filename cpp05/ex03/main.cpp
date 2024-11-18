/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:04 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/07/23 07:58:26 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_get_form(Intern& intern, Bureaucrat& paul, const std::string formName, const std::string target)
{
	AForm		*form;
	
	try
	{
		form = intern.makeForm(formName, target);
		paul.signForm(*form);
		form->execute(paul);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

int	main(void)
{
	Bureaucrat	paul("Paul", 5);
	Intern		intern;

	std::cout << "Test Presidential Pardon" << std::endl;
	test_get_form(intern, paul, "presidential pardon", "home");
	std::cout << std::endl;
	std::cout << "Test Shrubbery Creation" << std::endl;
	test_get_form(intern, paul, "shrubbery creation", "work");
	std::cout << std::endl;
	std::cout << "Test Robotomy Request" << std::endl;
	test_get_form(intern, paul, "robotomy request", "school");
	std::cout << std::endl;
	std::cout << "Test with Wrong Name" << std::endl;
	test_get_form(intern, paul, "wrong name", "beach");
	std::cout << std::endl;
	return (0);
}
