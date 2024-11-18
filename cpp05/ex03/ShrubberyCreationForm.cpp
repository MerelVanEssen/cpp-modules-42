/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:21 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 09:27:32 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 137), _target("default")
{
	std::cout << GRE "A default constructor is called for ShrubberyCreationForm" RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << GRE "A constructor with target: " << target << " is called for ShrubberyCreationForm" RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm(toCopy),
_target(toCopy.getTarget())
{
	std::cout << GRE "Copy constructor is used" RES << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED "ShrubberyCreationForm is destroyed" RES << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	if (&toCopy == this)
		return (*this);
	return (*this);
}

const std::string &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureau) const
{
	int			grade;
	std::string	fileName;
	std::string tree = {"                                                         . \n\
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@bd%%%bd%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,.. "};

	std::cout << BLU << bureau.getName() << " tries to execute a ShrubberyCreationForm" RES << std::endl;
	grade = bureau.getGrade();
	if (this->getSigned() == false)
		throw NotSigned();
	else if (grade < 1)
		throw GradeTooHighException();
 	else if (grade <= 145 && grade <= 137)
	{
		fileName = this->getTarget();
		fileName.append("_shrubbery");
		std::ofstream MyFile(fileName);
		MyFile << tree;
		MyFile.close();
		std::cout << YEL "A tree is drawed in the file: " << fileName << RES << std::endl;
	}
	else
		throw GradeTooLowException();
}
