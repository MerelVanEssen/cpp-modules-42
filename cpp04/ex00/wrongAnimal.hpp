/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:53:04 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 13:34:59 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

# define	RES	"\033[0m"
# define	RED	"\033[31m"
# define	GRE	"\033[32m"
# define	YEL	"\033[33m"

class WrongAnimal
{
	private:

	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		virtual ~WrongAnimal();
		
		WrongAnimal&		operator=(const WrongAnimal&);
		void				makeSound(void) const;
		const std::string	getType(void) const;
};

#endif