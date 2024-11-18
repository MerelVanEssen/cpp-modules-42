/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:08 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 09:27:02 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", 25, 5), _target("default") 
{
	std::cout << GRE "A default constructor is called for PresidentialPardonForm" RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target) 
{
	std::cout << GRE "A constructor with target: " << target << " is called for PresidentialPardonForm" RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) : AForm(toCopy),
	_target(toCopy.getTarget()) 
{
	std::cout << GRE "Copy constructor is used" RES << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED "PresidentialPardonForm is destroyed" RES << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (&toCopy != this)
		return (*this);
	return (*this);
}

const std::string &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& bureau) const
{
	int	grade;

	std::cout << BLU << bureau.getName() << " tries to execute a PresidentialPardonForm" RES << std::endl;
	grade = bureau.getGrade();
	if (this->getSigned() == false)
		throw NotSigned();
	else if (grade < 1)
		throw GradeTooHighException();
	else if (grade <= 25 && grade <= 5)
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" RES << std::endl;
	else
		throw GradeTooLowException();
}
