/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:44:07 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/10/02 10:18:43 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

void	subject_test(void)
{
	std::cout << GRE "Test from the subject" RES << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	small_test(void)
{
	std::cout << GRE "Small test" RES << std::endl;
	int			amount = 5;
	int			nr;
	Span 		sp(amount);

	for(int i = 0; i < amount; i++)
	{
		try
		{
			nr = rand() % 20;
			std::cout << "add nr: " << nr << std::endl;
			sp.addNumber(nr);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RES << std::endl;
			break ;
		}
	}
	try
	{
		std::cout << "Length span: " << sp.getAddedNumbers() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	big_test(void)
{
	std::cout << GRE "Test 10000 adding number by number" RES << std::endl;
	int		amount = 10000;
	Span	span(amount);
	
	for(int i = 0; i < amount; i++)
	{
		try
		{
			span.addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RES << std::endl;
			break ;
		}
	}
	try
	{
		std::cout << "Length span: " << span.getAddedNumbers() << std::endl;
		std::cout << YEL "Longest span: " << span.longestSpan() << RES << std::endl;
		std::cout << YEL "Shortest span: " << span.shortestSpan() << RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	range_test_good(void)
{
	std::cout << GRE "Test add range of 10000 with space 10000" RES << std::endl;
	std::vector<int>	numbers;
	int					amount = 10000;
	Span				span(amount);

	for(int i = 0; i < amount; i++)
		numbers.push_back(rand());
	try
	{
		span.addNumbers(numbers);
		std::cout << YEL "Length span: " << span.getAddedNumbers() << RES << std::endl;
		std::cout << YEL "Longest span: " << span.longestSpan() << RES << std::endl;
		std::cout << YEL "Shortest span: " << span.shortestSpan() << RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	range_test_full(void)
{
	std::cout << GRE "Test add range of 10000 with space 9995" RES << std::endl;
	std::vector<int>	numbers;
	int					amount = 10000;
	Span				span(amount - 5);

	for(int i = 0; i < amount; i++)
		numbers.push_back(rand());
	try
	{
		span.addNumbers(numbers);
		std::cout << YEL "Length span: " << span.getAddedNumbers() << RES << std::endl;
		std::cout << YEL "Longest span: " << span.longestSpan() << RES << std::endl;
		std::cout << YEL "Shortest span: " << span.shortestSpan() << RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	exception_full(void)
{
	std::cout << GRE "Try adding too much numbers (10), space(8)" RES << std::endl;
	std::vector<int>	numbers;
	int					amount = 10;
	Span				sp(amount - 2);
	
	for(int i = 0; i < amount; i++)
	{
		try
		{
			sp.addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RES << std::endl;
			break ;
		}
	}
	try
	{
		std::cout << "Length span: " << sp.getAddedNumbers() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	exception_not_enough_numbers(void)
{
	std::cout << GRE "Not enough numbers, first zero, than 1" RES << std::endl;
	Span	span(1);
	
	try
	{
		std::cout << "Length span: " << span.getAddedNumbers() << std::endl;
		std::cout << YEL "Longest span: " << span.longestSpan() << RES << std::endl;
		std::cout << YEL "Shortest span: " << span.shortestSpan() << RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	try
	{
		span.addNumber(rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	try
	{
		std::cout << "Length span: " << span.getAddedNumbers() << std::endl;
		std::cout << YEL "Longest span: " << span.longestSpan() << RES << std::endl;
		std::cout << YEL "Shortest span: " << span.shortestSpan() << RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
}

void	exception_range(void)
{
	std::cout << GRE "Range test with zero/one and full" RES << std::endl;
	std::vector<int>	numbers;
	int					amount = 10;
	Span				span(1);

	for(int i = 0; i < amount; i++)
		numbers.push_back(rand());
	try
	{
		span.addNumbers(numbers);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	try
	{
		std::cout << "Length span: " << span.getAddedNumbers() << std::endl;
		std::cout << YEL "Longest span: " << span.longestSpan() << RES << std::endl;
		std::cout << YEL "Shortest span: " << span.shortestSpan() << RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}	
}

int	main(void)
{
	srand((unsigned) time(NULL));
	subject_test();
	std::cout << std::endl;
	small_test();
	std::cout << std::endl;
	big_test();
	std::cout << std::endl;
	range_test_good();
	std::cout << std::endl;
	range_test_full();
	std::cout << std::endl;
	exception_full();
	std::cout << std::endl;
	exception_not_enough_numbers();
	std::cout << std::endl;
	exception_range();
	return (0);
}