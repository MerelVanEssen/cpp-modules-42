/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:27:32 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 12:10:17 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "A post: :" << a++ << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	std::cout << std::endl << YEL "OWN TESTS" << std::endl;

	std::cout << "---------------Bigger, smaller, equal-----------" RES << std::endl;
	Fixed	c(13.53f);
	Fixed	d(14.70f);
	
	if (d < c)
		std::cout << d << " is smaller than " << c << std::endl;
	else
		std::cout << d << " is not smaller than " << c << std::endl;
	if (d > c)
		std::cout << d << " is bigger than " << c << std::endl;
	else
		std::cout << d << " is not bigger than " << c << std::endl;
	if (d == c)
		std::cout << d << " is equal than " << c << std::endl;
	else
		std::cout << d << " is not equal than " << c << std::endl;
	if (d != c)
		std::cout << d << " is not equal to " << c << std::endl;
	else
		std::cout << d << " is equal to " << c << std::endl;

	std::cout << YEL "----------------- +-/* -------------------------" RES << std::endl;
	std::cout << "d + c = " << d + c << std::endl;
	std::cout << "d - c = " << d - c << std::endl;
	std::cout << "d * c = " << d * c << std::endl;
	std::cout << "d / c = " << d / c << std::endl;
	
	std::cout << YEL "------ pre, postfix increment, decrement--------" RES << std::endl;
	std::cout << "before: " << d << " d++: " << d++ << "  after: " << d << std::endl;
	std::cout << "before: " << d << " ++d: " << ++d << "  after: " << d << std::endl;
	std::cout << "before: " << d << " d--: " << d-- << "  after: " << d << std::endl;
	std::cout << "before: " << d << " --d: " << --d << "  after: " << d << std::endl;
	
	std::cout << YEL "----------(const) min, max, --------------------" RES << std::endl;
	std::cout << "min " << Fixed::min(d, c) << std::endl;
	std::cout << "max " << Fixed::max(d, c) << std::endl;
	std::cout << "min const " << Fixed::min(d, c) << std::endl;
	std::cout << "max const " << Fixed::max(d, c) << std::endl;
	return (0);
}
