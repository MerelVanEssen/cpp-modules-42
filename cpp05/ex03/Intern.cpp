/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:17:29 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/07/18 09:53:56 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << GRE "An Intern is made" RES << std::endl;
}

Intern::Intern(const Intern& toCopy) = default;

Intern::~Intern(void)
{
	std::cout << RED "An Intern is deleted" RES << std::endl;
}

Intern&	Intern::operator=(const Intern& intern)
{
	if (this == &intern)
		return (*this);
	return(*this);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	const std::string	forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int					i;
	i = 0;
	while (i < 3)
	{
		if (forms[i].compare(name) == 0)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw NoMatchingForm();
	}
	return (nullptr);
}
