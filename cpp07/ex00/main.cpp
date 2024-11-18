/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:38:07 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/02 07:33:54 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "test.hpp"

void	subject_test(void)
{
	int a = 2;
	int b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << GRE "Test subject" RES << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
}

void	swap_int(void)
{
	int	x 			= 5;
	int	y			= 8;

	std::cout << GRE "Swap int" RES << std::endl;
	std::cout << "y: " << y << " & x: " << x << std::endl;
	::swap(x, y);
	std::cout << "y: " << y << " & x: " << x << std::endl;
}

void	swap_double(void)
{
	double	x 		= 5.67;
	double	y 		= 8.42;

	std::cout << GRE "Swap double" RES << std::endl;
	std::cout << "y: " << y << " & x: " << x << std::endl;
	::swap(x, y);
	std::cout << "y: " << y << " & x: " << x << std::endl;
}

void	swap_string(void)
{
	std::string	x 	= "String One";
	std::string	y 	= "String Two";

	std::cout << GRE "Swap std::string" RES << std::endl;
	std::cout << "y: " << y << " & x: " << x << std::endl;
	::swap(x, y);
	std::cout << "y: " << y << " & x: " << x << std::endl;
}

void	swap_class(void)
{
	test	testerX(4);
	test	testerY(3);

	std::cout << GRE "Swap class" RES << std::endl;
	std::cout << "y: " << testerX.getNr() << " & x: " << testerY.getNr() << std::endl;
	::swap(testerX, testerY);
	std::cout << "y: " << testerX.getNr() << " & x: " << testerY.getNr() << std::endl;
}

void	min_max_int(void)
{
	int	x = 5;
	int	y = 8;

	std::cout << GRE "Min/max int" RES << std::endl;
	std::cout << "y: " << y << " & x: " << x << std::endl;
	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;
}

void	min_max_double(void)
{
	double	x = 5.67;
	double	y = 8.42;

	std::cout << GRE "Min/max double" RES << std::endl;
	std::cout << "y: " << y << " & x: " << x << std::endl;
	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;
}

void	min_max_string(void)
{
	std::string	x = "String One";
	std::string	y = "String Two";

	std::cout << GRE "Min/max std::string" RES << std::endl;
	std::cout << "y: " << y << " & x: " << x << std::endl;
	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;
}

void	min_max_class(void)
{
	test	testerX(4);
	test	testerY(3);

	std::cout << GRE "Min/max class" RES << std::endl;
	std::cout << "y: " << testerX.getNr() << " & x: " << testerY.getNr() << std::endl;
	std::cout << "min: " << ::min(testerX, testerY) << std::endl;
	std::cout << "max: " << ::max(testerX, testerY) << std::endl;
}

int	main(void)
{
	subject_test();
	swap_int();
	swap_double();
	swap_string();
	swap_class();
	min_max_int();
	min_max_double();
	min_max_string();
	min_max_class();
}