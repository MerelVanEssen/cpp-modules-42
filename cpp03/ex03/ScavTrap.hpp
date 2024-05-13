/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:45:56 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 11:34:57 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(const ScavTrap&);
		virtual ~ScavTrap();

		ScavTrap&		operator=(const ScavTrap&);
		virtual void 	attack(const std::string& target);
		void			guardGate(void);
};

#endif