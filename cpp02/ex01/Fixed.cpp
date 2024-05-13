/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:18:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 08:05:08 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GRE "Constructor called" RES << std::endl;
	this->_fixedPointNr = 0;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << GRE "Copy constructor called" RES << std::endl;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << GRE "Copy assignment operator called" RES << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
}

Fixed::Fixed(const int nr)
{
	this->_fixedPointNr = nr * (1 << _FractionalBits);
	std::cout << GRE "Int constructor called" RES << std::endl;
}

Fixed::Fixed(const float nr)
{
	this->_fixedPointNr = roundf(nr * (1 << _FractionalBits));
	std::cout << GRE "Float constructor called" RES << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called" RES << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointNr);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNr = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointNr) / (1 << this->_FractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointNr >> this->_FractionalBits);
}

std::ostream&	operator<<(std::ostream &stream, Fixed const &obj)
{
	stream << obj.toFloat();
	return (stream);
}
