/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:51 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 09:26:04 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(75), _gradeToExecute(75)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade)
{
}

AForm::AForm(const AForm& toCopy) :
_name(toCopy.getName()), _signed(toCopy.getSigned()), _gradeToSign(toCopy.getGradeToSign()), _gradeToExecute(toCopy.getGradeToExecute())
{
	std::cout << GRE "Copy constructor used" RES << std::endl;
}

AForm::~AForm(void)
{
}

const std::string&	AForm::getName(void) const
{
	return(this->_name);
}

const bool&	AForm::getSigned(void) const
{
	return(this->_signed);
}

const int&	AForm::getGradeToSign(void) const
{
	return(this->_gradeToSign);
}


const int&	AForm::getGradeToExecute(void) const
{
	return(this->_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& toPrint)
{
	os << "Name: " << toPrint.getName() << "  Signed: " << toPrint.getSigned();
	return (os);
}