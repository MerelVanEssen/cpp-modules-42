/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:49:02 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/06 13:58:42 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAEPON_HPP
# define WAEPON_HPP

# define	RESET	"\033[0m"
# define	RED		"\033[31m"
# define	GREEN	"\033[32m"
# define	BLUE	"\033[34m"
# define	YELLOW	"\033[33m"

# include <iostream>
 
class	Weapon
{
	private:
		std::string	_type;
	public:
		Weapon();
		Weapon(std::string);
		~Weapon();

		std::string	getType(void) const;
		void		setType(std::string);
};

#endif