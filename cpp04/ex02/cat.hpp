/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:19 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 12:01:42 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "animal.hpp"
# include "brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
	private:
		Brain*	_brain;
	protected:

	public:
		Cat();
		Cat(const Cat&);
		~Cat();

		Cat&		operator=(const Cat&);
		
		void		makeSound(void) const;
		void		setIdea(int, const std::string);
		std::string	getIdea(int);
};

#endif