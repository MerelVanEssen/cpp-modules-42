/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:45:42 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 08:55:20 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap&);
		virtual ~FragTrap();

		FragTrap&	operator=(const FragTrap&);
		void		highFivesGuys(void);
};

#endif