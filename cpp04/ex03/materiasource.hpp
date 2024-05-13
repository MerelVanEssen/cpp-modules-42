/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:40:40 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/08 10:25:54 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# define RES "\033[0m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[33m"

# include <iostream>
# include "amateria.hpp"
# include "imateriasource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_iMateriaSource[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource&);

		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const & type);
};

#endif