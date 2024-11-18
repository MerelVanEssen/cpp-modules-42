/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:53:30 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 07:56:58 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <limits.h>
# include <bits/stdc++.h>
# include <cmath>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter& toCopy);

		ScalarConverter&	operator=(const ScalarConverter& toCopy);
		
		static void			charLiterals(char c);
		static void			intLiterals(std::string i);
		static void			floatLiterals(std::string f);
		static void			doubleLiterals(std::string d);
	public:
		static void			convert(std::string str);
};

#endif