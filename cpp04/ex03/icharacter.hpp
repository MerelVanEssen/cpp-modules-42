/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:36:21 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:46:58 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <iostream>
# include "amateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual 					~ICharacter() {}
		virtual std::string const&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};

#endif