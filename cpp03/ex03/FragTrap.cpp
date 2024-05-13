/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:45:45 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 08:45:47 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GRE "Default FragTrap is created" << std::endl;
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << GRE << name << " FragTrap is created" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << GRE "FragTrap Copy constructor is called" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << RED "FragTrap Destructor is called for: " << this->_name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GRE "Hej! Give me a high five!" << std::endl;
}
