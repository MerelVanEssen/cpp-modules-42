/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:45 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/13 10:35:15 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form(void);
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& toCopy);
		~Form(void);

		Form&	operator=(const Form& toCopy);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat& bureau);

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

std::ostream&	operator<<(std::ostream& os, const Form& toPrint);

#endif