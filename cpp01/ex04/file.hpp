/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:23:09 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/06 12:39:52 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <iostream>
# include <fstream>

# define OUT "out"

class	File
{
	private:
		std::string		_infile;
		std::ifstream	_fdIn;
		std::ofstream	_fdOut;
	public:
		File();
		File(char*);
		~File();

		int		openFile(void);
		int		replaceString(std::string, std::string);
		int		setFilename(char*);
};

#endif