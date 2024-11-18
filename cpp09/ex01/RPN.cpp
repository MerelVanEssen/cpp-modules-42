/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:56:49 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/14 07:55:46 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& toCopy)
{
	if (&toCopy != this)
		this->input_ = toCopy.input_;
}

RPN::~RPN(void)
{

}

RPN&	RPN::operator=(const RPN& toCopy)
{
	if (&toCopy != this)
		this->input_ = toCopy.input_;
	return (*this);
}

void	RPN::validateInput(const std::string &str) const
{
	int		amountFirstDigits;
	bool	first;
	char	c;
	
	amountFirstDigits = 0;
	first = true;
	for (size_t i = 0; i < str.size(); i++)
	{
		c = str.at(i);
		if (!(isdigit(c) || c == '-' || c == '+' || c == '/' || c == '*' || c == ' '))
			throw invalidInput();
		if (isdigit(c))
		{
			amountFirstDigits++;
			if (i + 1 < str.length() && std::isdigit(str.at(i + 1)))
				throw invalidInput();
		}
		else if (c != ' ')
		{
			if (first == true && amountFirstDigits < 2)
				throw invalidInput();	
			first = false;
		}
	}
	if (first == true)
		throw invalidInput();
}

int	RPN::calculateSom(int nr1, int nr2, char token)
{
	if (token == '+')
	{
		if (static_cast<long long>(nr1) + nr2 > std::numeric_limits<int>::max())
			throw overflow();
		return (nr1 + nr2);
	}
	else if (token == '-')
	{
		if (static_cast<long long>(nr1) + nr2 < std::numeric_limits<int>::min())
			throw overflow();
		return (nr1 - nr2);
	}
	else if (token == '/')
	{
		if (nr2 == 0)
			throw devideZero();
		if (static_cast<long long>(nr1) / nr2 < std::numeric_limits<int>::min())
			throw overflow();
		return (nr1 / nr2);
	}
	else if (token == '*')
	{
		if (static_cast<long long>(nr1) * nr2 > std::numeric_limits<int>::max())
			throw overflow();
		return (nr1 * nr2);
	}
	return (0);
}

bool	RPN::checkOneDigit(const std::string &str, int &sum) const
{
	bool	foundDigit;

	foundDigit = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str.at(i) != ' ')
		{
			if (std::isdigit(str.at(i)))
			{
				if (foundDigit == true)
					return (false);
				sum = str.at(i) - 48;
				foundDigit = true;
			}
			else
				return (false);
		}
	}
	return (foundDigit);
}

void	RPN::calculateSegment(void)
{
	int		nr1;
	int		nr2;
	char	token;
	
	if (this->input_.size() < 3)
		throw invalidInput();
	token = this->input_.top();
	this->input_.pop();
	nr1 = this->input_.top();
	this->input_.pop();
	nr2 = this->input_.top();
	this->input_.top() = calculateSom(nr2, nr1, token);
}

int		RPN::calculator(std::string str)
{
	size_t	i;
	int		sum;

	if (checkOneDigit(str, sum))
		return (sum);
	validateInput(str);
	i = 0;
	while (i < str.size())
	{
		if (str.at(i) != ' ' && !std::isdigit(str.at(i)))
		{
			this->input_.push(str.at(i));
			calculateSegment();
		}
		else if (str.at(i) != ' ')
			this->input_.push((str.at(i) - 48));
		i++;
	}
	if (this->input_.size() > 1)
		throw invalidInput();
	return (this->input_.top());
}

const char* RPN::invalidInput::what() const noexcept
{
	return ("Error: Invalid Input");
}

const char* RPN::devideZero::what() const noexcept
{
	return ("Error: Sum contains devided by zero");
}

const char* RPN::overflow::what() const noexcept
{
	return ("Error: overflow");
}
