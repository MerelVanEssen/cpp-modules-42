/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:15:20 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/19 12:31:43 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::printContacts(int index) const
{
	int	i;

	if (index == 0)
	{
		std::cout << RED << "No contacts yet" << RESET << std::endl;
		return ;
	}
	i = 0;
	std::cout << YELLOW << "     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME" << RESET << std::endl;
	while (i < index && i < SIZE)
	{
		this->_contact[i].printContact(i);
		i++;
	}
}

static int	validateInput(std::string input, int max_index)
{
	int	index;
	int	max;

	if (input.empty())
		return (0);
	if (max_index > SIZE)
		max_index = SIZE;
	std::istringstream iss(input);
	iss >> index;
	if (iss.fail() || !(index > 0 && index <= max_index))
		return (0);
	return (index);
}

void	PhoneBook::searchContact(int index_total)
{
	std::string	input;
	int			index;
	
	index = 0;
	std::cout << GREEN << "Choose an index: " << RESET;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			return ;
		}
		index = validateInput(input, index_total);
		if (index > 0)
			break ;
		else
			std::cout << RED << "No valid option. " << RESET << "Try again: " << std::flush;
	}
	this->_contact[index - 1].returnContact();
}

static std::string	takeInput(void)
{
	std::string	input;

	std::cout << GREEN << "ADD, SEARCH or EXIT: " << RESET;
	while(1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl;
			std::clearerr(stdin);
			std::cin.clear();
			return ("");
		}
		if (input.empty())
		{
			std::cin.clear();
			std::cout << RED << "Enter a valid action." << RESET << std::endl;
			std::cout << GREEN << "ADD, SEARCH or EXIT: " << RESET << std::flush;
		}
		else
			return (input);
	}
	return (input);
}

void	PhoneBook::inputCmd(void)
{
	std::string input;
	int			index;

	index = 0;
	std::cout << YELLOW "-PHONEBOOK- Make a choice:" << std::endl;
	std::cout << "ADD a contact, SEARCH a contact or EXIT" << std::endl;
	while (1)
	{
		input = takeInput();
		if (input.empty())
			continue ;
		else if (input.compare("EXIT") == 0)
			return ;
		else if (input.compare("ADD") == 0)
		{
			this->_contact[index % SIZE].addContact(index);
			index++;
		}
		else if (input.compare("SEARCH") == 0)
		{
			printContacts(index);
			if (index > 0)
				searchContact(index);
		}
		else
			std::cout << RED << "Type a valid action:" << RESET << std::endl;
	}
}