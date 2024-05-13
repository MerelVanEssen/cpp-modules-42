/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imateriasource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:48:02 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 13:47:09 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <iostream>

class AMateria;

class IMateriaSource
{
	public:
		virtual 			~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;
};

#endif