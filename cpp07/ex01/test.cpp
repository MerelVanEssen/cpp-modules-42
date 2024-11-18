/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:39:13 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 08:40:13 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

test::test(void) : _nr(5)
{
}

test::test(const test& toCopy) : _nr(toCopy.getNr())
{
}

test::~test(void)
{
}

test	test::operator=(const test& toCopy)
{
	if(this != &toCopy)
		this->setNr(toCopy.getNr());
	return (*this);
}

void	test::setNr(int nr)
{
	this->_nr = nr;
}
const int&	test::getNr() const
{
	return (this->_nr);
}

std::ostream&	operator<<(std::ostream& os, const test& toPrint)
{
	os << toPrint.getNr();
	return (os);
}
