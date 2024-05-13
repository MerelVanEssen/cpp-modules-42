/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:23:52 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 08:03:29 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPointNr;
		static const int	_FractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		
		Fixed&	operator=(const Fixed &);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;	
};

std::ostream&	operator<<(std::ostream&, Fixed const&);

#endif