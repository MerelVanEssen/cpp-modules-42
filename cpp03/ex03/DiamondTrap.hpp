/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:03:26 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 09:08:24 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string);
		DiamondTrap(const DiamondTrap&);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap&);
		using			ScavTrap::attack;
		void			whoAmI(void);
		void			printPoints(void) const;
};

#endif