/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:34:22 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:43:50 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GRE "Cure Constructor called" RES << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure& obj)
{
	std::cout << GRE "Copy Constructor Cure called" RES << std::endl;
	*this = obj;
}

Cure::~Cure()
{
	std::cout << RED "Cure destructor called" RED << std::endl;
}

Cure&	Cure::operator=(const Cure& obj)
{
	this->_type = obj._type;
	return (*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << YEL "* heals " << target.getName() << "'s wounds *" RES << std::endl;
}

AMateria*	Cure::clone() const
{
	Cure* newCure = new Cure();
	return (newCure);
}
