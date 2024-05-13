/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:47:39 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 08:21:50 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB(std::string);
		~HumanB();

		void	attack(void);
		void	setWeapon(Weapon&);
};

#endif