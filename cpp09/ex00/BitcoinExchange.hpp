/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:42:43 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/14 07:57:23 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
# define BITCOIN_HPP

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
# include <regex>
# include <map>
# include <iomanip>
# include <cctype> 

class BitcoinExchange
{
	private:
		std::map<std::string, double>	pairs_;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& toCopy);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& toCopy);
		void				loadData(void);
		bool				valideString(int option, const std::string &check) const;
		double				getExchangeRate(const std::string &data) const;
		double				getValue(const std::string &value) const;
		void				calculateExchange(const std::string &fileName);

		class wrongFile : public std::exception
		{
			const char* what() const noexcept override;
		};
		class noPositiveNr : public std::exception
		{
			const char* what() const noexcept override;
		};
		class tooLargeNr : public std::exception
		{
			const char* what() const noexcept override;
		};
		class badInput : public std::exception
		{
			const char* what() const noexcept override;
		};
};

#endif
