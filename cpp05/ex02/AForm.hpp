/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:14:55 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/08 07:50:17 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm(void);
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& toCopy);
		virtual ~AForm(void);

		virtual void		execute(Bureaucrat const &) const = 0;
		const std::string &	getName(void) const;
		const bool &		getSigned(void) const;
		const int &			getGradeToSign(void) const;
		const int &			getGradeToExecute(void) const;

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
		class NotSigned : public std::exception
		{
			const char* what() const noexcept override
			{
				return ("Form is not signed");
			};
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& toPrint);

#endif