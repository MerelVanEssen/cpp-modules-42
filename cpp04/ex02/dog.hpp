/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:11 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 12:01:47 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "animal.hpp"
# include "brain.hpp"
# include <iostream>

class Dog : public AAnimal
{
	private:
		Brain*	_brain;
	protected:

	public:
		Dog();
		Dog(const Dog&);
		~Dog();
		
		Dog&		operator=(const Dog&);

		void		makeSound(void) const;
		void		setIdea(int, const std::string);
		std::string	getIdea(int);
};

#endif