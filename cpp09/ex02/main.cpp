/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:32:00 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/18 13:23:00 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

std::chrono::duration<double>	addNumbersDeque(int argc, char **argv, std::deque<int> &deq);
std::chrono::duration<double>	addNumbersVector(int argc, char **argv, std::vector<int> &vect);
int								checkLenNumber(char *str, int &j);
void							testVector(int argc, char **argv);
void							testDeque(int argc, char **argv);

int	main(int argc, char **argv)
{	
	if (argc < 2)
	{
		std::cerr << RED "No arguments" RES << std::endl;
		return (1);
	}
	try
	{
		testDeque(argc, argv);
		testVector(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	return (0);
}

void	testDeque(int argc, char **argv)
{
	std::chrono::high_resolution_clock::time_point	start;
	std::chrono::high_resolution_clock::time_point	end;
	std::chrono::duration<double> 					time;
	PmergeMe										pmm;
	std::deque<int>									deq;

	time = pmm.addNumbersDeque(argc, argv, deq);
	std::cout << BLU "DEQUE TEST" RES << std::endl;
	std::cout << GRE "Before: ";
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i] << " ";
	std::cout << std::endl;
	start = std::chrono::high_resolution_clock::now();
	pmm.sortDeque(deq);
	end = std::chrono::high_resolution_clock::now();
	time += std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	std::cout << "After: ";
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i] << " ";
	std::cout << RES << std::endl;
	std::cout << YEL "Time to process a range of " << deq.size() << " elements with std::deque : " <<
	std::fixed << std::setprecision(5) << (time.count() * 1000) << " us" RES << std::endl;
}

void	testVector(int argc, char **argv) 
{
	std::chrono::high_resolution_clock::time_point	start;
	std::chrono::high_resolution_clock::time_point	end;
	std::chrono::duration<double> 					time;
	PmergeMe										pmm;
	std::vector<int>								vect;	

	time = pmm.addNumbersVector(argc, argv, vect);
	std::cout << BLU "VECTOR TEST" RES << std::endl;
	std::cout << GRE "Before: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;	
	start = std::chrono::high_resolution_clock::now();
	pmm.sortVector(vect);
	end = std::chrono::high_resolution_clock::now();
	time += std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	std::cout << "After: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << RES << std::endl;	
	std::cout << YEL "Time to process a range of " << vect.size() << " elements with std::vector : " <<
	std::fixed << std::setprecision(5) << (time.count() * 1000) << " us" RES << std::endl;
}

int	PmergeMe::checkLenNumber(char *str, int &j)
{
	unsigned long long	longNr;
	int					start;

	start = j;
	while (str[j] && std::isdigit(str[j]))
		j++;
	if (str[j] != '\0' && str[j] != ' ')
		throw wrongChar();
	if (j > 10)
		throw tooHighNumber();
	longNr = std::stoull(str + start);
	if (longNr > std::numeric_limits<int>::max())
		throw tooHighNumber();
	return (static_cast<int>(longNr));
}
