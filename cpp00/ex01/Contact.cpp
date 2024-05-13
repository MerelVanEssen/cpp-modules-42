#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

static bool	checkValidNumber(std::string phonenumber)
{
	for (char ch : phonenumber)
	{
		if (!std::isdigit(ch) && !std::isspace(ch))
		{
			std::cout << RED << "Only digits - " << RESET;
			return (false);
		}
	}
	return (true) ;
}

static std::string	getValue(std::string str, bool flag)
{
	std::string	input;

	std::cout << str;
	std::getline(std::cin, input);
	while (std::cin.eof() || input.empty() || flag)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::clearerr(stdin); //after ctrl+d (closes pipe stdin -> reset)
			std::cin.clear();
			return ("No input");
		}
		else if (flag && !input.empty() && checkValidNumber(input))
			break ;
		std::cout << RED << "Please enter info for " << RESET << str;
		std::cin.clear();
		std::getline(std::cin, input);
	}
	return (input);
}

void	Contact::addContact(int index)
{
	this->_firstname = getValue("Firstname: ", false);
	this->_lastname = getValue("Lastname: ", false);
	this->_nickname = getValue("Nickname: ", false);
	this->_phonenr = getValue("Phonenumber: ", true);
	this->_secret = getValue("Darkest secret: ", false);
	this->_index = index;
}

static void	printValue(std::string str)
{
	if (str.size() >= 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << "|" << std::setfill (' ') << std::setw (10) << str;
}
  
void	Contact::printContact(int index) const
{
	std::cout << std::setfill (' ') << std::setw (10) << index + 1;
	printValue(this->_firstname);
	printValue(this->_lastname);
	printValue(this->_nickname);
	std::cout << std::endl;
}

void	Contact::returnContact(void) const
{
	std::cout << YELLOW << "--------------------" << std::endl;
	std::cout << YELLOW << "Contact information:" << RESET << std::endl;
	std::cout << "Firstname: " << this->_firstname << std::endl;
	std::cout << "Lastname: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phonenumber: " << this->_phonenr << std::endl;
	std::cout << "Secret: " << this->_secret << std::endl;
	std::cout << YELLOW << "--------------------" << std::endl;
}