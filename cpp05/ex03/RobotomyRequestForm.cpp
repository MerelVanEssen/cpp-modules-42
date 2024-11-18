/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:13 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 09:27:17 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45), _target("default")
{
	std::cout << GRE "A default constructor is called for RobotomyRequestForm" RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << GRE "A constructor with target: " << target << " is called for RobotomyRequestForm" RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) : AForm(toCopy),
_target(toCopy.getTarget())
{
	std::cout << GRE "Copy constructor is used" RES << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED "RobotomyRequestForm is destroyed" RES << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	if (&toCopy == this)
		return (*this);
	return (*this);
}

const std::string &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& bureau) const
{
	int	grade;
	int	nr;

	std::cout << BLU << bureau.getName() << " tries to execute a RobotomyRequestForm" RES << std::endl;
	srand(time(0));
	grade = bureau.getGrade();
	if (this->getSigned() == false)
		throw NotSigned();
	else if (grade < 1)
		throw GradeTooHighException();
	else if (grade <= 72 && grade <= 45)
	{
		std::cout << BLU "DRRRRRRRRRRRRRGGGGGGRRRRGRGR DRILLING...." RES << std::endl;
		nr = rand() % 2;
		if (nr == 1)
			std::cout << BLU << this->getTarget() << " has been robotomized successfully" RES << std::endl;
		else
			std::cout << BLU << this->getTarget() << " has failed during the robotomy" RES << std::endl;
	}
	else
		throw GradeTooLowException();
}
