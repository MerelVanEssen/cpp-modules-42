/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:07:33 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 11:35:55 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << GRE "A default ClapTrap is created" RES << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_damage = 0;	
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GRE << name << " is created" << RES << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << GRE "Copy constructor is called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED "Destructor is called for: " << this->_name << std::endl; 
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	this->_name = obj._name;
	this->_energyPoints = obj._energyPoints;
	this->_hitPoints = obj._hitPoints;
	this->_damage = obj._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << RED << this->_name << " has no energy to attack" RES << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout	<< YEL "ClapTrap " << this->_name << " attacks "
				<< target << " causing " << this->_damage 
				<< " points of damage." RES << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;
	this->_hitPoints -= amount;
	std::cout << YEL << this->_name << " takes " << amount << " of damage " RES;
	std::cout << "(left: " << this->_hitPoints << ")" << std::endl;
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << this->_name << " died" RES << std::endl;
		this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << RED << this->_name << " has no energy left to attack" RES << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	std::cout << GRE << this->_name << " recieved " << amount << " of health points back" RES << std::endl;
	this->_energyPoints--;
}
