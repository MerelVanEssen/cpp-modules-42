/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:50:23 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 11:44:36 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
	std::cout << GRE "Dog\tConstructor called" RES << std::endl;
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
}

Dog&	Dog::operator=(const Dog& obj)
{
	this->type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << YEL << this->type << ":\tWOOF" RES << std::endl;
}