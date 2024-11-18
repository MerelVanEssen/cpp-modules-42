/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:53:06 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/26 09:23:22 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

void	serialize_deserialize_test(void)
{
	Data		*dat = new Data('a', 42, 0.4f, 4.2);
	Data		*new_dat;
	uintptr_t	nr;	

	std::cout << GRE "Data before:" RES << std::endl;
	std::cout << dat << std::endl;
	nr = Serializer::serialize(dat);
	std::cout << BLU "uintrptr_t raw: " << nr << RES << std::endl;
	new_dat = Serializer::deserialize(nr);
	std::cout << GRE "Data after:" RES << std::endl;
	std::cout << new_dat << std::endl;
	delete dat;
}

void	null_ptr_test(void)
{
	Data		*dat_null;
	Data		*dat_null_deserialized;
	uintptr_t 	nr;

	std::cout << GRE "Input nullptr" RES << std::endl;
	dat_null = nullptr;
	nr = Serializer::serialize(dat_null);
	dat_null_deserialized = Serializer::deserialize(nr);
	std::cout << dat_null_deserialized << std::endl;
}

void	cc_is_operator_test(void)
{
	Data		*dat = new Data('a', 42, 0.4f, 4.2);
	Data		*forCopy;

	forCopy = new Data(*dat);
	std::cout << GRE "Data from copy after use copy constructor:" RES << std::endl;
	std::cout << forCopy << std::endl;
	
	Data	operatorCopy = *dat;
	std::cout << GRE "Data from copy after use = operator:" RES << std::endl;
	std::cout << &operatorCopy << std::endl;

	delete dat;
	delete forCopy;
}

int	main(void)
{
	serialize_deserialize_test();
	null_ptr_test();
	cc_is_operator_test();
	return (0);
}