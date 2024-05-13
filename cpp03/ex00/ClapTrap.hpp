/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:07:57 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 07:18:35 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"

# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_damage;
	public:
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap&);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
