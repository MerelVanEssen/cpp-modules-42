/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:31:51 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/13 10:27:21 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "character.hpp"

Character::Character()
{
	int	i;
	
	std::cout << GRE "Default constructor Character" RES << std::endl;
	i = 0;
	while (i < 4)
	{
		this->_materia[i] = NULL;
		i++;
	}
}

Character::Character(std::string const& name)
{
	int	i;

	std::cout << GRE << name << " constructor Character" RES << std::endl;
	this->_name = name;
	i = 0;
	while (i < 4)
	{
		this->_materia[i] = NULL;
		i++;
	}
}

Character::Character(const Character& obj)
{
	std::cout << GRE "Copy Constructor Ice called" RES << std::endl;
	*this = obj;
}

Character::~Character()
{
	std::cout << RED "Character destructor called" RES << std::endl;
}

Character&	Character::operator=(const Character& obj)
{
	this->_name = obj._name;
	int	i;
	
	i = 0;
	while (i < 4)
	{
		this->_materia[i] = obj._materia[i];
		i++;
	}
	return (*this);
}

void	Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			return ;
		}
		i++;
	}
	std::cout << RED "Inventory is full" RES << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)	
	{
		std::cout << "Wrong index, 0 - 3" << std::endl;
		return ;
	}
	if (this->_materia[idx])
	{
		std::cout << this->_name << " throughs his materia away on index: " << idx << std::endl;
		this->_materia[idx] = NULL;
	}
	else
		std::cout << "Nothing to unequip on this index" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->_materia[idx])
		this->_materia[idx]->use(target);
	else
		std::cout << YEL "This is " << target.getName() << RES << std::endl;
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

void	Character::setName(const std::string name)
{
	this->_name = name;
}