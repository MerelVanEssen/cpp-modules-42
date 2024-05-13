/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:25 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 12:24:46 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# define	RES	"\033[0m"
# define	RED	"\033[31m"
# define	GRE	"\033[32m"
# define	YEL	"\033[33m"

# include <iostream>

class Animal
{
	private:

	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();
		
		Animal&				operator=(const Animal&);
		
		virtual void		makeSound(void) const;
		const std::string	getType(void) const;
};

#endif