/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:15:00 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/07/18 08:15:02 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade );
		Bureaucrat(const Bureaucrat& toCopy);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& toCopy);

		int					executeForm(const AForm& form);

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;
		void				setGrade(int grade);

		void				signForm(AForm& form);

		void				incrementGrade(void);
		void				decrementGrade(void);

		class GradeTooHighException : public std::exception
		{
			const char* what() const noexcept override
			{
				return ("Grade is too high");
			};
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const noexcept override
			{
				return ("Grade is too low");
			};
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat&);


#endif