/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:18:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 07:59:13 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GRE "Default constructor called" RES << std::endl;
	this->_fixedPointNr = 0;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called" RES << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << GRE "Copy constructor called" RES << std::endl;
	this->setRawBits(obj.getRawBits());
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << GRE "Copy assignment operator called" RES << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNr);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNr = raw;
}