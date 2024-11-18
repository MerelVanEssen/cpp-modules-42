/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:43 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/13 10:35:24 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(75), _gradeToExecute(75)
{
	std::cout << GRE "A default form is made with sign & execute grade 75" RES << std::endl; 
}

Form::Form(std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade)
{
	std::cout << GRE "Form " << name << " is made with sign grade: " << signGrade;
	std::cout << " & execute grade " << executeGrade << RES << std::endl; 
}

Form::Form(const Form& toCopy) : _name(toCopy.getName()), _gradeToSign(toCopy.getGradeToSign()), _gradeToExecute(toCopy.getGradeToExecute())
{
	this->_signed = toCopy.getSigned();
	std::cout << GRE "Copy constructor used" RES << std::endl;
}

Form::~Form(void)
{
	std::cout << RED "Form " << this->getName() << " is destroyed" RES << std::endl;
}

Form&	Form::operator=(const Form& toCopy)
{
	if (&toCopy != this)
		return (*this);
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return(this->_name);
}

bool	Form::getSigned(void) const
{
	return(this->_signed);
}

int	Form::getGradeToSign(void) const
{
	return(this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return(this->_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& toPrint)
{
	os << "Name: " << toPrint.getName() << "  Signed: " << toPrint.getSigned();
	return (os);
}