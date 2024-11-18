/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:38:12 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/02 07:20:57 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

test::test(void) : _nr(5)
{
}

test::test(int nr) : _nr(nr)
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
const int&	test::getNr(void) const
{
	return (this->_nr);
}

bool 	test::operator<(const test& tester) const
{
	return (this->_nr < tester.getNr());
}

bool 	test::operator>(const test& tester) const
{
	return (this->_nr > tester.getNr());
}

std::ostream&	operator<<(std::ostream& os, const test& toPrint)
{
	os << toPrint.getNr();
	return (os);
}
