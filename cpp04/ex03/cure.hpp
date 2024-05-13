/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:34:44 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:47:23 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[33m"

# include <iostream>
# include "icharacter.hpp"

class Cure : public AMateria
{
	private:
		std::string	_type;
	public:
		Cure();
		Cure(const Cure&);
		~Cure();

		Cure&		operator=(const Cure&);
		
		void		use(ICharacter& target);
		AMateria*	clone() const;
};

#endif
