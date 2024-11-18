/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:47:26 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/10/02 10:54:55 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& toCopy) : MutantStack()
{
	(void)toCopy;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
	return (*this);
}

template<typename T>
typename 	MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename 	MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename 	MutantStack<T>::iterator	MutantStack<T>::begin(void) const
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename 	MutantStack<T>::iterator	MutantStack<T>::end(void) const
{
	return (std::stack<T>::c.end());
}

template<typename T>
void	MutantStack<T>::advance(typename MutantStack<T>::iterator& it, int nr)
{
	std::advance(it, nr);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::next(typename MutantStack<T>::iterator it, int nr)
{
	typename MutantStack<int>::iterator end;

	end = std::stack<T>::c.end();
	while (it != end && nr)
	{
		it++;
		nr--;
	}
	return (it);
}
  
template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::prev(typename MutantStack<T>::iterator it, int nr)
{
	typename MutantStack<int>::iterator begin;

	begin = std::stack<T>::c.begin();
	while (it != begin && nr)
	{
		it--;
		nr--;
	}
	return (it);
}

template<typename T>
constexpr typename std::stack<T>::container_type::difference_type	MutantStack<T>::\
	distance(typename MutantStack<T>::iterator it, typename MutantStack<T>::iterator it_two)
{
	return (std::distance(it, it_two));
}