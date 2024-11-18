/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:46:19 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/10/18 07:55:50 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(5), _addedNumbers(0)
{
}

Span::Span(unsigned int N) : _N(N), _addedNumbers(0)
{
}

Span::Span(const Span& toCopy) : _N(toCopy.getN()), _addedNumbers(toCopy.getAddedNumbers())
{
}

Span::~Span(void)
{
}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		this->_N = copy.getN();
		this->_addedNumbers = copy.getAddedNumbers();
	}
	return (*this);
}

void	Span::addNumber(int nr)
{
	if (this->_span.size() < this->_N)
	{
		this->_span.push_back(nr);
		this->_addedNumbers++;
	}
	else
		throw SpanIsFull();
}

int	Span::getN(void) const
{
	return (this->_N);
}

int	Span::getAddedNumbers(void) const
{
	return (this->_addedNumbers);
}

bool sortfunction(int i, int j)
{
	return (i < j);
}

int Span::shortestSpan(void)
{
	int	shortest;
	int	size;
	int	i;

	size = this->_span.size();
	if (size < 2)
		throw NotEnoughNr();
	std::sort(this->_span.begin(), this->_span.end(), sortfunction);
	shortest = this->_span[1] - this->_span[0];
	i = 1;
	while (i < size)
	{
		if (this->_span[i] - this->_span[i - 1] < shortest)
			shortest = this->_span[i] - this->_span[i - 1];
		i++;
	}
	return (shortest);
}

int Span::longestSpan(void)
{
	if (this->_span.size() < 2)
		throw NotEnoughNr();
	else
	{
		std::sort(this->_span.begin(), this->_span.end(), sortfunction);
		return (this->_span.at(this->_span.size() - 1) - this->_span.at(0));
	}
}

void	Span::addNumbers(std::vector<int> range)
{
	unsigned int	numbers;

	numbers = this->getAddedNumbers();
	if (numbers + range.size() <= this->_N)
	{
		this->_span.insert(this->_span.end(), range.begin(), range.end());
		this->_addedNumbers += range.size();
	}
	else
		throw SpanIsFull();
}

const char *Span::SpanIsFull::what() const noexcept
{
	return ("Span is full");
}

const char *Span::NotEnoughNr::what() const noexcept
{
	return ("Not enough numbers"); 
}
