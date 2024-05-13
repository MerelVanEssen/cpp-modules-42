/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:32:02 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/06 12:39:41 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

int	File::replaceString(std::string s1, std::string s2)
{
	std::string	str;
	std::size_t	pos;
	std::size_t	posNext;
	std::size_t	lenS1;
	std::size_t	lenS2;
	
	if (s1.empty())
	{
		std::cerr << "No valid search" << std::endl;
		return (1);
	}
	lenS1 = s1.length();
	lenS2 = s2.length();
	std::getline(this->_fdIn, str, '\0');
	pos = 0;
	posNext = str.find(s1);
	while (posNext != std::string::npos)
	{
		this->_fdOut << str.substr(pos, posNext - pos);
		this->_fdOut << s2;
		pos = posNext + lenS1;
		posNext = str.find(s1, pos);
	}
	this->_fdOut << str.substr(pos, posNext - pos);
	return (0);
}
