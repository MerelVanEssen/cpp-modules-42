/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:45:11 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 09:10:36 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal() : type("Thing")
{
	std::cout << GRE "Animal\tConstructor called" RES << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << GRE "Animal\tCopy constructor called" RES << std::endl;
	*this = obj;
}

Animal::~Animal()
{
	std::cout << RED "Animal\tDestructor called" RES << std::endl;
}

Animal&	Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << YEL <<this->type << ":\tSSSSSTTT" RES << std::endl;
}

const std::string	Animal::getType(void) const
{
	return (this->type);
}
