/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:47:29 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/14 07:55:39 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

# include <iostream>
# include <algorithm>
# include <stack>
# include <limits>
# include <sstream> 

class RPN
{
	private:
		std::stack<int>	input_;

		bool	checkOneDigit(const std::string &str, int &sum) const;
		void	validateInput(const std::string &str) const;
		int		calculateSom(int nr1, int nr2, char token);
		void	calculateSegment(void);
	public:
		RPN(void);
		RPN(const RPN& toCopy);
		~RPN(void);

		RPN&	operator=(const RPN& toCopy);
		int		calculator(std::string str);

		class invalidInput : public std::exception
		{
			const char* what() const noexcept override;
		};
		class devideZero : public std::exception
		{
			const char* what() const noexcept override;
		};
		class overflow : public std::exception
		{ 
			const char* what() const noexcept override;
		};
};

#endif