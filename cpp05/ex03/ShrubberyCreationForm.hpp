/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:25 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/07/18 09:37:33 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;
	const std::string	_name;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& toCopy);

	const std::string &	getTarget(void) const;
	void				execute(const Bureaucrat& bureau) const;
};


#endif