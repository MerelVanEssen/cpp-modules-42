/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:31:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:44:19 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GRE "Ice Constructor called" RES << std::endl;
	this->_name = "ice";
}

Ice::Ice(const Ice& obj)
{
	std::cout << GRE "Copy Constructor Ice called" RES << std::endl;
	*this = obj;
}

Ice::~Ice()
{
	std::cout << RED "Ice destructor called" RES << std::endl;
}

Ice&	Ice::operator=(const Ice& obj)
{
	this->_type = obj._type;
	return (*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << YEL "* shoots an ice bold at " << target.getName() << " *" RES << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria* newIce = new Ice();
	return (newIce);
}