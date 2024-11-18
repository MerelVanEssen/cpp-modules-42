/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:38:28 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/02 07:48:12 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

template <typename T>
void	iter(T *address, int len, void (*function)(T&))
{
	int	i;

	i = 0;
	if (!address || !function)
		return ;
	while (i < len)
	{
		function(address[i]);
		i++;
	}
};

template <typename T>
void	printArray(T &address)
{
	std::cout << "Array contains: " << address << std::endl;
}

#endif