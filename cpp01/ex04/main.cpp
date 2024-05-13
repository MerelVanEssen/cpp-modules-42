/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:25:03 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/30 08:28:21 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

int	main(int argc, char **argv)
{
	File	file;
	char	infile[] = "Makefile";
	
	if (argc == 4 && file.setFilename(argv[1]) == 0)
	{
			if (file.openFile())
				return (1);
			file.replaceString(argv[2], argv[3]);
	}
	else
	{
		std::cerr << "Wrong amount of arguments" << std::endl;
		return (1);
	}

	return (0);
}
/*
	Testcases:
	"Makefile" "a" "++"		//longer
	"Makefile" "NAME" "+" 	//shorter
	"Makefile" "" "+" 		// empty (not valid)
	"Makefile" "a" "" 		// remove all a
	"" "a" "b" 				//not valid
*/