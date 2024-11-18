/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:47:35 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/17 09:53:58 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

void	stack_example()
{
	MutantStack<int>::iterator it;
	MutantStack<int> mstack;
	int	numbers[] = {2, 17, 3, 5, 737, 0};

	for (int i = 0; i < 2; i++)
		mstack.push(numbers[i]);
	std::cout << YEL "Top stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << RED "Removed top with pop (17)" RES << std::endl;
	std::cout << YEL "Size stack: " << mstack.size() << std::endl;
	for (int i = 2; i < 6; i++)
		mstack.push(numbers[i]);	
	it = mstack.begin();
	++it;
	--it;
	std::cout << BLU "Now in stack:\t\t\t";
	while (it != mstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
	std::stack<int> copy = s;
	std::cout << std::endl;
}

void	list_example()
{
	std::list<int> lstack;
	std::list<int>::iterator it;
	int	numbers[] = {2, 17, 3, 5, 737, 0};	

	for (int i = 0; i < 2; i++)
		lstack.push_back(numbers[i]);
	std::cout << YEL "Top stack: " << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << RED "Removed top with pop (17)" RES << std::endl;
	std::cout << YEL "Size stack: " << lstack.size() << std::endl;
	for (int i = 2; i < 6; i++)
		lstack.push_back(numbers[i]);
	it = lstack.begin();
	++it;
	--it;
	std::cout << BLU "Now in list:\t\t\t";
	while (it != lstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void	extra_stack()
{
	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	insert;
	MutantStack<int>			mstack;	
	int	numbers[] = {2, 17, 3, 5, 737, 0};

	for (int i = 0; i < 6; i++)
		mstack.push(numbers[i]);
	it = mstack.begin();
	std::cout << BLU "Now in stack:\t\t\t";
	while (it != mstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	it = mstack.begin();
	mstack.advance(it, 2);
	std::cout << YEL "Advance (move 2 up): ptr points:\t" << *it << std::endl;
	it = mstack.next(it, 2);
	std::cout << YEL "Next(move 2 up) ptr points:\t\t" << *it << std::endl;
	it = mstack.prev(it, 3);
	std::cout << YEL "Prev (move 3 back) ptr points:\t\t" << *it << std::endl;
	std::cout << YEL "Distance begin - end:\t\t\t" << mstack.distance(mstack.begin(), mstack.end()) << std::endl;
	std::cout << YEL "Size:\t\t\t\t\t" << mstack.size() << std::endl;

}

int main()
{
	std::cout << GRE "Stack example: " RES << std::endl;
	stack_example();
	std::cout << std::endl;
	std::cout << GRE "List example: " RES << std::endl;
	list_example();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << GRE "Stack extras: " RES << std::endl;
	extra_stack();
	std::cout << std::endl;
	return (0);
}