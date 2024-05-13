/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:52:58 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 09:11:07 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongThing")
{
	std::cout << GRE "WrongAnimal\tConstructor called" RES << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << GRE "WrongAnimal\tCopy constructor called" RES << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED "WrongAnimal\tDestructor called" RES << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& obj)
{
	this->type = obj.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << YEL << this->type << ":\tSSSSSTTT" RES << std::endl;
}

const std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
