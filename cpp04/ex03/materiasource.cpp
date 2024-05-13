/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:48:31 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 11:07:23 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materiasource.hpp"

MateriaSource::MateriaSource()
{
	int	i;

	std::cout << GRE "Default constructor MateriaSource" RES << std::endl;
	i = 0;
	while (i < 4)
	{
		this->_iMateriaSource[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << GRE "Copy constructor MateriaSource" RES << std::endl;
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->_iMateriaSource[i])
			delete this->_iMateriaSource[i];
		i++;
	}
	std::cout << RED "Destructor IMateriaSource" RES << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& obj)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->_iMateriaSource[i] = obj._iMateriaSource[i];
		i++;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* newMateria)
{
	int	i;

	i = 0;
	if (!this->_iMateriaSource[0])
	{
		this->_iMateriaSource[0] = newMateria;
		return ;
	}
	while (i < 4)
	{
		if (!this->_iMateriaSource[i])
		{
			this->_iMateriaSource[i] = newMateria;
			return ;
		}
		i++;
	}
	std::cout << RED "You have already four materias" RES << std::endl;
	delete newMateria;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->_iMateriaSource[i])
		{
			if (this->_iMateriaSource[i]->getType().compare(type) == 0)
				return (this->_iMateriaSource[i]);
		}
		i++;
	}
	std::cout << RED "Type not found" RES << std::endl;
	return (NULL);
}
