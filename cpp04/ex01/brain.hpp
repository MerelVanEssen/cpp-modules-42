/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:11:26 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 12:25:54 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# define	RES	"\033[0m"
# define	RED	"\033[31m"
# define	GRE	"\033[32m"
# define	YEL	"\033[33m"

# include <iostream>

class Brain
{
	private:

	protected:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const Brain&);
		virtual ~Brain();
		
		Brain&		operator=(const Brain&);
		
		void		setIdea(int, const std::string);
		std::string	getIdea(int);

};

#endif