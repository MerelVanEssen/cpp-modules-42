/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:48:52 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/06 14:21:29 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	std::cout << GREEN << "Created weapon: " << type << std::endl;
	setType(type);
}

Weapon::Weapon()
{
	std::cout << GREEN << "A weapon is created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << RED << this->_type << " is destroyed" << std::endl;
}

std::string	Weapon::getType(void) const
{
	std::string type = this->_type;
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}