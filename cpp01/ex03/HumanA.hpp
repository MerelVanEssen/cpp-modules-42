/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:48:08 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 08:21:39 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(std::string, Weapon&);
		~HumanA();

		void	attack(void);
		void	setWeapon(Weapon);
};

#endif