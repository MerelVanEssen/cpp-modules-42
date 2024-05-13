/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:48:58 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 09:05:24 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << GRE "WrongCat\tConstructor called" RES << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << GRE "WrongCat\tCopy constructor called" RES << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << RED "WrongCat\tDestructor called" RES << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj)
{
	this->type = obj.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << YEL << this->type << ":\tMIAUW" RES << std::endl;
}