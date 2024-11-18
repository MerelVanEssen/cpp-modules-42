/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:10:23 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/26 13:11:16 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

template <typename T>
void swap(T& x, T& y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T	min(T x, T y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T>
T	max(T x, T y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif