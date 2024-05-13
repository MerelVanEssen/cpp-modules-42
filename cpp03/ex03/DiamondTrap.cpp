/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:21:56 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:09 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{	
	this->_name = "default";
	ClapTrap::_name = "Default_clap_name";
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	std::cout << GRE << this->_name << " DiamondTrap is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
	std::cout << GRE << this->_name << " DiamondTrap is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : FragTrap(obj), ScavTrap(obj)
{
	std::cout << GRE "DiamondTrap Copy constructor is called" << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED "Diamond Destructor is called for: " << this->_name << std::endl; 
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << YEL "I'm " << this->_name << " and ClapTrap is " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::printPoints(void) const
{
	std::cout	<< RES "Name: " << this->_name << std::endl
				<< "Hitpoints: " << this->_hitPoints << std::endl
				<< "Energypoints: " << this->_energyPoints << std::endl
				<< "Attact damage: " << this->_attackDamage << std::endl;
}