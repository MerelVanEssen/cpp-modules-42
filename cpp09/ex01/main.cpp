/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:49:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/13 12:26:35 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

void	extra_tests(std::string str)
{
	int		sum;
	RPN		rpn;

	try
	{
		std::cout << GRE "Try: " << str << " -> " RES;
		sum = rpn.calculator(str);
		std::cout << YEL << sum << RES << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	createOneString(char **argv, std::string& wholeString)
{
	argv++;
	while (*argv)
	{
		wholeString += *argv;
		wholeString += " ";
		argv++;
	}
}

int	main(int argc, char **argv)
{
	std::string	wholeString;
	RPN			rpn;
	int			sum;
	
	if (argc >= 2)
	{
		try
		{
			if (argc == 2)
			{
				sum = rpn.calculator(argv[1]);
				std::cout << GRE << argv[1] << " = " YEL << sum << RES << std::endl;
			}
			else
			{
				createOneString(argv, wholeString);
				sum = rpn.calculator(wholeString);
				std::cout << GRE << wholeString << " = " YEL << sum << RES << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RES << std::endl;
		}
	}
	else
		std::cerr << RED "Wrong amount of arguments" RES << std::endl;
	// EXTRA TESTS:
	std::cout << std::endl;
	std::cout << "Extra tests:" << std::endl;
	extra_tests("1     3 + 5-3/2 8-+ ");
	extra_tests("1 2 3 + - +");
	extra_tests("+ 2 3 +");
	extra_tests("1 +");
	extra_tests("1 2 + +");
	extra_tests("1 2 3 + - +");
	extra_tests("1 2 + 4 + -");
	extra_tests("1 + 5 4 + -");
	extra_tests("1 2");
	extra_tests("11 3 +");
	extra_tests("1 3 + 5 =");
	extra_tests("1 3 + 7 3 2 7 5 + +");
	extra_tests("1 3 + 7 3 2 7 5 + + + + + +");
	RPN	copy(rpn);
	RPN	isOperator = copy;
	return (0);
}