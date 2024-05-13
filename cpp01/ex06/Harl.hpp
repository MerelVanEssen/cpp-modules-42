/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:33:41 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/02 08:43:10 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include  <iostream>

# define	RESET	"\033[0m"
# define	RED		"\033[31m"
# define	GREEN	"\033[32m"
# define	YELLOW	"\033[33m"
# define	PURPLE	"\033[35m"
# define	BLUE	"\033[34m"

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif