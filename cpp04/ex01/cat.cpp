/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:48:51 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 11:46:34 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat()
{
	std::cout << GRE "Cat\tConstructor called" RES << std::endl;
	this->_brain = new Brain;
	type = "Cat";
}

Cat::Cat(const Cat& obj)
{
	std::cout << GRE "Cat\tCopy constructor called" RES << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << RED "Cat\tDestructor called" RES << std::endl;
	delete this->_brain;
}

Cat&	Cat::operator=(const Cat& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.type;
	this->_brain = new Brain;
	*this->_brain = *obj._brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << YEL << this->type << ":\tMIAUW" RES << std::endl;
}

void	Cat::setIdea(int nr, const std::string idea)
{
	this->_brain->setIdea(nr, idea);
}

std::string	Cat::getIdea(int nr)
{
	return (this->_brain->getIdea(nr));
}