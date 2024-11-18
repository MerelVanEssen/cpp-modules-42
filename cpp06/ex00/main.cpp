/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:53:14 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/26 08:50:21 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	test_char(void)
{
	std::cout << GRE "Char literals:" RES << std::endl;
	std::cout << BLU "'0':" RES << std::endl;
	ScalarConverter::convert("'0'");
	std::cout << BLU "'c':" RES << std::endl;
	ScalarConverter::convert("'c'");
	std::cout << BLU "'4':" RES << std::endl;
	ScalarConverter::convert("'4'");
	std::cout << BLU "'°':" RES << std::endl;
	ScalarConverter::convert("'°'");
}

void	test_int(void)
{
	std::cout << GRE "Int literals:" RES << std::endl;
	std::cout << BLU "0:" RES << std::endl;
	ScalarConverter::convert("0");
	std::cout << BLU "-42:" RES << std::endl;
	ScalarConverter::convert("-42");
	std::cout << BLU "42:" RES << std::endl;
	ScalarConverter::convert("42");
}

void	test_float(void)
{
	std::cout << GRE "Float literals:" RES << std::endl;
	std::cout << BLU "0.0f:" RES << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << BLU "-4.2f:" RES << std::endl;
	ScalarConverter::convert("-4.2f");
	std::cout << BLU "4.2f:" RES << std::endl;
	ScalarConverter::convert("4.2f");
	std::cout << BLU "42.0f:" RES << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << BLU "-inff:" RES << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << BLU "+inff:" RES << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << BLU "nanf:" RES << std::endl;
	ScalarConverter::convert("nanf");
}

void	test_double(void)
{
	std::cout << GRE "Double literals:" RES << std::endl;
	std::cout << BLU "0,0:" RES << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << BLU "-4,2:" RES << std::endl;
	ScalarConverter::convert("-4.2");
	std::cout << BLU "4,2:" RES << std::endl;
	ScalarConverter::convert("4.2");
	std::cout << BLU "-inf:" RES << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << BLU "+inf:" RES << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << BLU "nan:" RES << std::endl;
	ScalarConverter::convert("nan");
}

void	test_exceptions(void)
{
	std::cout << GRE "Exceptions:" RES << std::endl;
	std::cout << BLU "Random text:" RES << std::endl;
	ScalarConverter::convert("Random text");
	std::cout << BLU "---0:" RES << std::endl;
	ScalarConverter::convert("---0");
	std::cout << BLU "+-+:" RES << std::endl;
	ScalarConverter::convert("+-+");
	std::cout << BLU " :" RES << std::endl;
	ScalarConverter::convert(" ");
	std::cout << BLU "[]:" RES << std::endl;
	ScalarConverter::convert("[]");
	std::cout << BLU ":" RES << std::endl;
	ScalarConverter::convert("");
}

int	main(void)
{
	test_char();
	test_int();
	test_float();
	test_double();
	test_exceptions();
	return (0);
}