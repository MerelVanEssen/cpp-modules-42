/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:41:55 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 08:41:56 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[33m"

# include <iostream>

class ClapTrap
{
	private:
		
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
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