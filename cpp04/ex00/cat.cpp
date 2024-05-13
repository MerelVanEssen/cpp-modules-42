/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:48:51 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 10:25:12 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat()
{
	std::cout << GRE "Cat\tConstructor called" RES << std::endl;
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
}

Cat&	Cat::operator=(const Cat& obj)
{
	this->type = obj.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << YEL << this->type << ":\tMIAUW" RES << std::endl;
}