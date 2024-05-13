/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:46:02 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 09:16:17 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << GRE << "Default ScavTrap is created" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << GRE << name << " ScavTrap is created" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << GRE "ScavTrap Copy constructor is called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << this->_name << " ScavTrap is destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return (*this);
}

void 	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << RED << this->_name << " has no energie to attack." << std::endl;
		return ;	
	}
	std::cout	<< YEL "ScavTrap " << this->_name << " attacks "
				<< target << " causing " << this->_attackDamage 
				<< " points of damage." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
		return ;
	std::cout << YEL << this->_name << " is now in Gate Keeper Mode" << std::endl;
}