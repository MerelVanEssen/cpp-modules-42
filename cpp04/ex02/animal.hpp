/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:25 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 12:27:07 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# define	RES	"\033[0m"
# define	RED	"\033[31m"
# define	GRE	"\033[32m"
# define	YEL	"\033[33m"

# include <iostream>

class AAnimal
{
	private:

	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal&);
		virtual ~AAnimal();
		
		AAnimal&			operator=(const AAnimal&);

		virtual void		makeSound(void) const = 0; // making an abstract class
		const std::string	getType(void) const;
};

#endif