/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:32:58 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/19 12:31:59 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define	RESET	"\033[0m"
# define	RED		"\033[31m"
# define	GREEN	"\033[32m"
# define	YELLOW	"\033[33m"
# define	SIZE	8

class	Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenr;
		std::string	_secret;
		std::string	_index;
	public:
		Contact(void);
		~Contact(void);
		void	addContact(int);
		void	printContact(int) const;
		void	returnContact(void) const;
};

#endif