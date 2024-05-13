/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:29:11 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:47:18 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[33m"

# include <iostream>
# include "icharacter.hpp"

class Ice : public AMateria
{
	private:
		std::string	_name;
	public:
		Ice();
		Ice(const Ice&);
		~Ice();

		Ice&		operator=(const Ice&);
		
		void		use(ICharacter& target);
		AMateria*	clone() const;
};

#endif