/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:45:03 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/07 11:28:43 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
 #define ZOMBIE_H

 #include <iostream>

 # define	RESET	"\033[0m"
 # define	RED		"\033[31m"
 # define	GREEN	"\033[32m"
 # define	BLUE	"\033[34m"
 # define	YELLOW	"\033[33m"

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();
		
		void 		announce(void);
		Zombie*		newZombie(std::string name);
		void		randomChump(std::string name);
		std::string	getName(void) const;
		void		setName(std::string name);
};

#endif