/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:30:02 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 07:42:55 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string		&stringREF = str;

	std::cout << "Memory address string var:\t" << &str << std::endl;
	std::cout << "Memory addres held by strPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory addres held by strREF:\t" << &stringREF << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Value of string var: \t\t" << str << std::endl;
	std::cout << "Value pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t" << stringREF << std::endl; 
}

// Reference can not change after declaration! 
// It has no NULL value.
// Not necessay to dereference.