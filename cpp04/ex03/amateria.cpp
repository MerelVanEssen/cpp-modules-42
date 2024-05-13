/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:14:58 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 14:28:31 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "amateria.hpp"

AMateria::AMateria() : _type(" ")
{
	std::cout << GRE "Default constructor AMateria" RES << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << GRE "Constructor AMateria for " << type << RES << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << GRE "Copy constructor AMateria" RES << std::endl;
	*this = obj;
}

AMateria::~AMateria()
{
	std::cout << RED "Destructor AMateria" RES << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& obj)
{
	this->_type = obj._type;
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::setType(std::string type)
{
	this->_type = type;
}

void	AMateria::use(ICharacter& target)
{
	if (target.getName().compare("cure") == 0)
		std::cout << YEL "* heals " << target.getName() << "'s wounds *" RES << std::endl;
	else if (target.getName().compare("ice") == 0)
		std::cout << YEL "* shoots an ice bold at " << target.getName() << " *" RES << std::endl;
	else
		std::cout << YEL "* Nothing for" << target.getName() << " *" RES << std::endl;

}
