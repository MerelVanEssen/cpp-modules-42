/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:47:24 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 08:21:44 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << GREEN << name << " is created (HumanB)" << std::endl;
	this->_name = name;
	this->_weapon = nullptr;
}

HumanB::~HumanB()
{
	std::cout << RED << this->_name << " is destroyed (HumanB)" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon == nullptr)
		std::cout << BLUE << this->_name << " has no weapon and attacts with their hands" << std:: endl;
	else
		std::cout << BLUE << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}