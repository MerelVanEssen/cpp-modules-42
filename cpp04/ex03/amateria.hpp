/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:14:00 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:47:32 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[33m"

# include <iostream>
# include "icharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria&);
		virtual ~AMateria();

		AMateria&	operator=(const AMateria&);
		
		std::string const&	getType() const;
		void				setType(std::string);
		
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif