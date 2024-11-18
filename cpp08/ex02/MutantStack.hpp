/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:47:30 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/10/02 10:22:46 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
# define MUTANT_HPP

# include <iostream>
# include <stack>
# include <list>
# include <iterator>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		
	public:
		MutantStack(void);
		MutantStack(const MutantStack& toCopy);
		~MutantStack(void);
		
		MutantStack&	operator=(const MutantStack& toCopy);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::difference_type difference;
		
		iterator				begin();
		iterator				begin() const;
		iterator				end();
		iterator				end() const;
		void					advance(iterator& it, int nr);
		iterator				next(iterator it, int nr);
		iterator				prev(iterator it, int nr);
		constexpr difference	distance(iterator it, iterator it_two);
};

# include "MutantStack.tpp"

#endif