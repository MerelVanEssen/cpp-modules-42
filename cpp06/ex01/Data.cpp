/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:53:34 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/26 09:17:26 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _c('a'), _i(0), _f(0.0f), _d(0.0)
{
}

Data::Data(char c, int i, float f, double d) : _c(c), _i(i), _f(f), _d(d)
{
}

Data::Data(const Data& toCopy) :
	_c(toCopy.getChar()), _i(toCopy.getInt()), _f(toCopy.getFloat()), _d(toCopy.getDouble())
{
}

Data::~Data()
{
}

Data	Data::operator=(const Data& toCopy)
{
	if(this != &toCopy)
	{
		this->_c = toCopy.getChar();
		this->_i = toCopy.getInt();
		this->_f = toCopy.getFloat();
		this->_d = toCopy.getDouble();
	}
	return (*this);
}

const char&	Data::getChar(void) const
{
	return (this->_c);
}

const int&	Data::getInt(void) const
{
	return (this->_i);
}

const float&	Data::getFloat(void) const
{
	return (this->_f);
}

const double&	Data::getDouble(void) const
{
	return (this->_d);
}

std::ostream&	operator<<(std::ostream& os, const Data *toPrint)
{
	if (toPrint == nullptr)
	{
		os << "No data";
		return (os);
	}
	os << "char: \'" << toPrint->getChar() << "\'\nint: " << toPrint->getInt()
		<< "\nfloat: " << toPrint->getFloat() << "f\ndouble: " << toPrint->getDouble();
	return (os);
}
