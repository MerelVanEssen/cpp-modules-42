/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:48:07 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/14 07:57:10 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) : pairs_(toCopy.pairs_) { }

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
	if (this != &toCopy)
		this->pairs_ = toCopy.pairs_;
	return (*this);
}

void	BitcoinExchange::loadData(void)
{
	std::fstream	dataFile;
	std::string		valueStr;
	std::string		line;
	std::string		key;
	double			value;
	size_t			placeComma;

	dataFile.open("data.csv");
	if (!dataFile.is_open())
		throw wrongFile();
	while (!dataFile.eof())
	{
		if (!line.empty() && isdigit(line[0]))
		{
			placeComma = line.find(',');
			if (placeComma != std::string::npos && placeComma != 0 && line.size() - placeComma > 0)
			{
				valueStr = line.substr(placeComma + 1, line.size() - placeComma);
				value = std::stod(valueStr);
				key = line.substr(0, placeComma);
				this->pairs_.insert(std::pair<std::string,double>(key, value));
			}
		}
		std::getline(dataFile, line, '\n');
	}
	dataFile.close();
}

bool	BitcoinExchange::valideString(int option, const std::string &check) const
{
	if (option == 1 && check.find_first_not_of("1234567890-") != std::string::npos)
		return (true);
	if (option == 2 && check.find_first_not_of("1234567890-. ") != std::string::npos)
		return (true);
	if (option == 2 && std::count(check.begin(), check.end(), '.') > 1)
		return (true);
	return (false);
}

double	BitcoinExchange::getExchangeRate(const std::string &data) const
{
	std::map<std::string, double>::const_iterator	it;
	std::map<std::string, double>::const_iterator	previous;
	std::string										key;

	if (data.at(4) != '-' || data.at(7) != '-' || valideString(1, data))
		throw badInput();
	it = this->pairs_.begin();
	while (it != this->pairs_.end())
	{
		key = it->first;
		if (it == this->pairs_.begin() && data < key)
			return (it->second);
		else if (key == data)
			return (it->second);
		else if (key > data)
			return (previous->second);
		previous = it;
		it++;
	}
	return (previous->second);
}

double	BitcoinExchange::getValue(const std::string &line) const
{
	double		nr;
	std::string	value;

	if (line.size() < 12)
		throw badInput();
	value = line.substr(12, (line.size() - 12));
	if (valideString(2, value))
		throw badInput();
	if (value.find('.') != std::string::npos && value.find_first_of('.') > 4)
		throw tooLargeNr();
	if (value.find('.') == std::string::npos && value.size() > 4)
		throw tooLargeNr();
	try
	{
		nr = std::stod(value);
	}
	catch(const std::exception& e)
	{
		static_cast<void>(e);
		throw badInput();
	}
	if (nr < 0)
		throw noPositiveNr();
	return (nr);
}

void	BitcoinExchange::calculateExchange(const std::string &fileName)
{
	std::fstream	dataFile;
	std::string		line;
	std::string		date;
	double			value;
	double			exchangeRate;

	dataFile.open(fileName);
	if (!dataFile.is_open())
		throw wrongFile();
	while (!dataFile.eof())
	{
		std::getline(dataFile, line, '\n');
		if(!line.empty() && isdigit(line[0]))
		{
			try
			{
				if (line.size() < 14)
					throw badInput();
				date = line.substr(0, 10);
				exchangeRate = getExchangeRate(date);
				value = getValue(line);
				std::cout << date << " => " << value << " = " << exchangeRate * value << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << RED "Error: " << e.what() << " => " << line << RES << std::endl;
			}
		}
		else if (!line.empty() && line != "date | value")
			std::cerr << RED "Error: bad input => " << line << RES << std::endl;
	}
	dataFile.close();
}

const char *BitcoinExchange::wrongFile::what() const noexcept
{
	return ("could not open file");
}

const char *BitcoinExchange::noPositiveNr::what() const noexcept
{
	return ("not a positive number.");
}

const char *BitcoinExchange::tooLargeNr::what() const noexcept
{
	return ("too large a number.");
}

const char *BitcoinExchange::badInput::what() const noexcept
{
	return ("bad input");
}