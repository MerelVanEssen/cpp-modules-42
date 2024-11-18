/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:53:37 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/21 08:08:47 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

# include <iostream>
# include <ostream>

class Data
{
	private:
		char	_c;
		int		_i;
		float	_f;
		double	_d;
	public:
		Data(void);
		Data(char c, int i, float f, double d);
		Data(const Data& toCopy);
		~Data(void);

		Data			operator=(const Data& toCopy);

		const char&		getChar(void) const;
		const int&		getInt(void) const;
		const float&	getFloat(void) const;
		const double&	getDouble(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Data* toPrint);

#endif