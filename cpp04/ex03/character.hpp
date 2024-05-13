/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:32:51 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/13 10:26:55 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[33m"

# include "amateria.hpp"
# include "icharacter.hpp"
# include "ice.hpp"
# include "cure.hpp"
# include <iostream>

class AMateria; // forward declaration

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_materia[4];
	public:
		Character();
		Character(std::string const& type);
		Character(const Character&);
		~Character();
		
		Character&			operator=(const Character&);

		std::string const&	getName() const;
		void				setName(const std::string);
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif