/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:17:32 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/07/23 07:57:46 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		
	public:
		Intern(void);
		Intern(const Intern& toCopy);
		~Intern(void);

		Intern&	operator=(const Intern& toCopy);

		AForm* makeForm(const std::string name, const std::string target);

		class NoMatchingForm : public std::exception
		{
			const char* what() const noexcept override
			{
				return ("No matching form found");
			};
		};
};

#endif