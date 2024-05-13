/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:51:19 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/03 10:31:14 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "animal.hpp"
# include <iostream>

class Cat : public Animal
{
	private:

	protected:

	public:
		Cat();
		Cat(const Cat&);
		~Cat();

		Cat&	operator=(const Cat&);
		void	makeSound(void) const;
};

#endif