/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:50:23 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 12:07:19 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
	std::cout << GRE "Dog\tConstructor called" RES << std::endl;
	this->_brain = new Brain;
	
	type = "Dog";
}

Dog::Dog(const Dog& obj)
{
	std::cout << GRE "Dog\tCopy constructor called" RES << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << RED "Dog\tDestructor called" RES << std::endl;
	delete this->_brain;
}

Dog&	Dog::operator=(const Dog& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.type;
	this->_brain = new Brain;
	*this->_brain = *obj._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << YEL << this->type << ":\tWOOF" RES << std::endl;
}

void	Dog::setIdea(int nr, const std::string idea)
{
	this->_brain->setIdea(nr, idea);
}

std::string	Dog::getIdea(int nr)
{
	return (this->_brain->getIdea(nr));
}