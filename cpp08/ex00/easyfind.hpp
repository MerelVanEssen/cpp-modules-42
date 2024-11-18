/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:42:05 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/17 08:52:52 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
# define EASY_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <exception>
# include <array>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

template<typename T>
typename T::const_iterator	easyFind(const T integers, int find_nr)
{
	typename T::const_iterator nr;

	nr = std::find(integers.begin(), integers.end(), find_nr);
	if (nr == integers.end())
		throw "Value not found";
	return (nr);
}

#endif