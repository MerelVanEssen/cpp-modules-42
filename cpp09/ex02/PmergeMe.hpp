/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:32:06 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/14 07:52:01 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>
# include <deque>
# include <vector>
# include <utility>
# include <limits>
# include <chrono>
# include <iomanip>
# include <exception>

typedef std::vector<std::pair<int, int>>	VectorP;
typedef std::deque<std::pair<int, int>>		DequeP;

class	PmergeMe
{
	private:
		int	struggler_;

		int 			generateJacobsthalNr(int n);
		int				checkLenNumber(char *str, int &j);
		// Vector
		bool			makePairsVector(VectorP &dubbleVect, std::vector<int> &vect);
		void			sortReverseVector(VectorP &vectorPair, int left, int right);
		void			mergeVector(VectorP &vectorPair, int left, int middle, int right);
		void			insertionVector(VectorP &vectorPair, std::vector<int> &vect);
		// Deque
		bool			makePairsDeque(DequeP &dequePair, std::deque<int> &deq);
		void			sortReverseDeque(DequeP &dequePair, int left, int right);
		void			mergeDeque(DequeP &dequePair, int left, int middle, int right);
		void			insertionDeque(DequeP &dequePair, std::deque<int> &deq);
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& toCopy);
		~PmergeMe();

		PmergeMe&		operator=(const PmergeMe& toCopy);

		std::chrono::duration<double>	addNumbersVector(int argc, char **argv, std::vector<int> &vect);
		std::chrono::duration<double>	addNumbersDeque(int argc, char **argv, std::deque<int> &deq);
		
		void			sortVector(std::vector<int> &vect);
		void			sortDeque(std::deque<int> &deq);

		class tooHighNumber : public std::exception 
		{ 
			const char* what() const noexcept override; 
		};
		class wrongChar : public std::exception
		{
			const char* what() const noexcept override;
		};
};

#endif