/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:53:26 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/26 08:48:33 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy)
{
	(void)toCopy;	
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& toCopy)
{
	(void)toCopy;
	return (*this);
}

void	ScalarConverter::charLiterals(char c)
{
	if (c >= 32 && c <= 127)
		std::cout << "CHAR: \'" << c << "\'" << std::endl;
	else
		std::cout << RED "Non displayable" RES << std::endl; 
	if (static_cast<int>(c) >= INT_MIN || static_cast<int>(c) <= INT_MAX)
		std::cout << "INT: " << static_cast<int>(c) << std::endl;
	else
		std::cout << "INT: impossible" << std::endl;
	if (static_cast<float>(c) - static_cast<int>(c) == 0)
		std::cout << "FLOAT: " << static_cast<float>(c) << ".0f" << std::endl;
	else
		std::cout << "FLOAT: " << static_cast<float>(c) << "f" << std::endl;
	if (static_cast<double>(c) - static_cast<int>(c) == 0)
		std::cout << "DOUBLE: " << static_cast<double>(c) << ".0" << std::endl;
	else
		std::cout << "DOUBLE: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::intLiterals(std::string i)
{
	long int	nr;

	try
	{
		nr = std::stol(i);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED "No valid integer: " << i << RES << std::endl;
		return ;
	}
	if (std::isprint(nr) && !std::isdigit(nr))
		std::cout << "CHAR: \'" << static_cast<char>(nr) <<  "\'" << std::endl;
	else
		std::cout << "CHAR: Non displayable" << std::endl;
	if (nr >= INT_MIN || nr <= INT_MAX)
		std::cout << "INT: " << nr << std::endl;
	else
		std::cout << "INT: impossible" << std::endl;
	std::cout << "FLOAT: " <<  static_cast<float>(nr) << ".0f" << std::endl;
	if (static_cast<double>(nr) - static_cast<int>(nr) == 0)
		std::cout << "DOUBLE: " << static_cast<double>(nr) << ".0" << std::endl;
	else
		std::cout << "DOUBLE: " << static_cast<double>(nr) << std::endl;
}

void	ScalarConverter::floatLiterals(std::string f)
{
	float nr;

	nr = std::stof(f);
	if (!std::isnan(nr) && ! std::isinf(nr) && std::isprint(static_cast<int>(nr)))
		std::cout << "CHAR: \'" << static_cast<char>(nr) <<  "\'" << std::endl;
	else
		std::cout << "CHAR: impossible" << std::endl;
	if (nr >= -2147483648 || nr <= 2147483647.0)
		std::cout << "INT: " << static_cast<int>(nr) << std::endl;
	else
		std::cout << "INT: impossible" << std::endl;
	if (nr - static_cast<int>(nr) == 0)
		std::cout << "FLOAT: " << nr << ".0f" << std::endl;
	else
		std::cout << "FLOAT: " << nr << "f" << std::endl;
	if (static_cast<double>(nr) - static_cast<int>(nr) == 0)
		std::cout << "DOUBLE: " << static_cast<double>(nr) << ".0" << std::endl;
	else
		std::cout << "DOUBLE: " << static_cast<double>(nr) << std::endl;	
}

void	ScalarConverter::doubleLiterals(std::string d)
{
	double		nr;
	std::string	f;

	nr = std::stod(d);
	if (!std::isnan(nr) && !std::isinf(nr) && std::isprint(static_cast<int>(nr)))
		std::cout << "CHAR: \'" << static_cast<char>(nr) <<  "\'" << std::endl;
	else
		std::cout << "CHAR: impossible" << std::endl;
	if (nr >= INT_MIN || nr <= INT_MAX)
		std::cout << "INT: " << static_cast<int>(nr) << std::endl;
	else
		std::cout << "INT: impossible" << std::endl;
	if (nr - static_cast<int>(nr) == 0)
		f = ".0f";
	else
		f = "f";
	if ((std::isnan(nr) || std::isinf(nr)) && d[0] == '+')
		std::cout << "FLOAT: +" << static_cast<float>(nr) << f << std::endl;
	else
		std::cout << "FLOAT: " << static_cast<float>(nr) << f << std::endl;
	if (nr - static_cast<int>(nr) == 0)
		std::cout << "DOUBLE: " << nr << ".0" << std::endl;
	else
		std::cout << "DOUBLE: " << nr << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	char	*end;
	
	if (str.length() == 0)
	{
		std::cout << RED "No valid string" RES << std::endl;
		return ;
	}
	for (char& c : str)
	{
		if (std::isprint(c) == false)
		{
			std::cout << RED "String contains a nonprintable character" RES << std::endl;
			return ;
		}
	}
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (charLiterals(str[1]));
	std::strtol(str.c_str(), &end, 10);
	if (*end == '\0')
		return (intLiterals(str));
	std::strtof(str.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
		return (floatLiterals(str));
	std::strtod(str.c_str(), &end);
	if (*end == '\0')
		return (doubleLiterals(str));
	std::cout << RED "String is not a char, int, float and double" RES << std::endl;
}