/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:18:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 12:19:13 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNr(0)
{
	std::cout << GRE "Constructor called" RES << std::endl;
}

Fixed::Fixed(const Fixed& t)
{
	//std::cout << GRE "Copy constructor called" RES << std::endl;
	*this = t;
}

Fixed::Fixed(const int nr)
{
	this->_fixedPointNr = nr * (1 << _FractionalBits);
}

Fixed::Fixed(const float nr)
{
	this->_fixedPointNr = nr * (1 << _FractionalBits);
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

Fixed&	Fixed::operator=(const Fixed& toCopy)
{
	if (this != &toCopy)
		this->setRawBits(toCopy.getRawBits());
	return (*this);
}

bool Fixed::operator>(const Fixed &obj)
{
	if (this->_fixedPointNr > obj._fixedPointNr)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &obj)
{
	if (this->_fixedPointNr < obj._fixedPointNr)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &obj)
{
	if (this->_fixedPointNr >= obj._fixedPointNr)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &obj)
{
	if (this->_fixedPointNr<= obj._fixedPointNr)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &obj)
{
	if (this->_fixedPointNr == obj._fixedPointNr)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &obj)
{
	if (this->_fixedPointNr != obj._fixedPointNr)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed &obj)
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj)
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj)
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj)
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed	Fixed::operator++(int) //post
{
	Fixed	temp(*this);

	temp._fixedPointNr = this->_fixedPointNr++;
	return (temp);
}

Fixed	Fixed::operator--(int) //post
{
	Fixed	temp(*this);

	temp._fixedPointNr = this->_fixedPointNr--;
	return (temp);
}

Fixed&	Fixed::operator++(void) //pre
{
	++this->_fixedPointNr;
	return (*this);
}

Fixed&	Fixed::operator--(void) //pre
{
	--this->_fixedPointNr;
	return (*this);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream &stream, Fixed const &toCopy)
{
	stream << toCopy.toFloat();
	return (stream);
}
