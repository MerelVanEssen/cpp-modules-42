/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:23:06 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/07 07:27:53 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

File::File()
{
}

File::~File()
{
	this->_fdIn.close();
	this->_fdOut.close();
}

int	File::setFilename(char *filename)
{
	this->_infile = filename;
	if (this->_infile.empty())
	{
		std::cout << "No valid name." << std::endl;
		return (1);
	}
	return (0);
}

int	File::openFile(void)
{
	this->_fdIn.open(this->_infile, std::ios::in);
	if (!this->_fdIn.is_open())
	{
		std::cerr << "_fdIn fails." << std::endl;
		return (1);
	}
	this->_fdOut.open(this->_infile + ".replace", std::ios::out | std::ios::trunc);
	if (!this->_fdOut.is_open())
	{
		std::cerr << "_fdOut fails." << std::endl;
		this->_fdIn.close();
		return (1);
	}
	return (0);
}

