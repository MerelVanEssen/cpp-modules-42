/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:48:35 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 08:21:32 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	std::cout << GREEN << name << " is created (HumanA)" << std::endl;
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << RED << this->_name << " is destroyed (HumanA)" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << BLUE << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}