/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:45:11 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 13:05:45 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

AAnimal::AAnimal() : type("Thing")
{
	std::cout << GRE "AAnimal\tConstructor called" RES << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj)
{
	std::cout << GRE "AAnimal\tCopy constructor called" RES << std::endl;
	*this = obj;
}

AAnimal::~AAnimal()
{
	std::cout << RED "AAnimal\tDestructor called" RES << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& obj)
{
	this->type = obj.type;
	return (*this);
}

// void	AAnimal::makeSound(void) const
// {
// 	std::cout << YEL <<this->type << ":\tSSSSSTTT" RES << std::endl;
// }

const std::string	AAnimal::getType(void) const
{
	return (this->type);
}
