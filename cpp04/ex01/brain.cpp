/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:15:00 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 12:26:19 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
	std::cout << GRE "Brain\tConstructor called" RES << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << GRE "Brain\tCopy constructor called" RES << std::endl;
	*this = obj;
}

Brain::~Brain()
{
	std::cout << RED "Brain\tDestructor called" RES << std::endl;
}

Brain&	Brain::operator=(const Brain& obj)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		this->_ideas[i] = obj._ideas[i];
		i++;
	}
	return (*this);
}

void	Brain::setIdea(int nr, const std::string idea)
{
	this->_ideas[nr] = idea;
}

std::string	Brain::getIdea(int nr)
{
	return (this->_ideas[nr]);
}
