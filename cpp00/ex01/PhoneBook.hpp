/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:33:26 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/19 12:33:14 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

# define	RESET	"\033[0m"
# define	RED		"\033[31m"
# define	GREEN	"\033[32m"
# define	YELLOW	"\033[33m"
# define	SIZE	8

class	PhoneBook
{
	private:
		Contact	_contact[SIZE];
	public:
		PhoneBook();
		~PhoneBook();
		void	inputCmd(void);
		void	addContact(int);
		void	printContacts(int) const;
		void	searchContact(int);
};

#endif