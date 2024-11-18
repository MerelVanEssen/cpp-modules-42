/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:38 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 09:23:58 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(75)
{
	std::cout << GRE "A Default Bureaucrat is made with grade 75" RES << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(75)
{
	std::cout << GRE "Bureaucrat " << name << " is made with grade 75" RES << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		this->setGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << RED "Correction for " << name << " is made" RES << std::endl;
		return ;
	}
	std::cout << GRE "Bureaucrat " << name << " is made with grade " << grade << RES << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy.getName()), _grade(toCopy.getGrade())
{
	std::cout << GRE "Copy constructor is used" RES << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << this->getName() << " is destroyed" RES << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& toCopy)
{
	if (&toCopy != this)
		this->_grade = toCopy.getGrade();
	return (*this);
}

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	std::cout << BLU << this->getName() << " signed " << form.getName() << RES << std::endl;	
}

const std::string &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int &	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		this->_grade = 1;
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		this->_grade = 150;
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& toPrint)
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade();
	return (os);
}
