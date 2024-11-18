/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:32:03 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/11/18 13:23:12 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }

PmergeMe::PmergeMe(const PmergeMe& toCopy) : struggler_(toCopy.struggler_) { }

PmergeMe::~PmergeMe() { }

PmergeMe&	PmergeMe::operator=(const PmergeMe& toCopy)
{
	if (this != &toCopy)
		this->struggler_ = toCopy.struggler_;
	return (*this);
}

// GETTERS
int PmergeMe::generateJacobsthalNr(int n)
{
	if (n <= 1)
		return (n);
	return (generateJacobsthalNr(n - 1) + 2 * generateJacobsthalNr(n - 2));
}

// VECTOR
void	PmergeMe::sortVector(std::vector<int>  &vect)
{
	std::vector<int>::iterator	it;
	VectorP						vectorPair;
	bool						struggler;
	size_t						len;

	if (vect.empty() || vect.size() == 1)
		return ;
	len = vect.size();
	struggler = makePairsVector(vectorPair, vect);
	sortReverseVector(vectorPair, 0, vectorPair.size() - 1);
	vect.reserve(len);
	insertionVector(vectorPair, vect);
	if (struggler)
	{
		it = std::lower_bound(vect.begin(), vect.end(), this->struggler_);
		if (it == vect.end())
			vect.push_back(this->struggler_);
		else
			vect.insert(it, this->struggler_);
	}
}

bool	PmergeMe::makePairsVector(VectorP &vectorPair, std::vector<int> &vect)
{
	bool	struggler;

	struggler = false;
	if (vect.size() % 2 != 0)
	{
		struggler = true;
		this->struggler_ = vect[vect.size() - 1];
		vect.pop_back();
	}
	vectorPair.reserve(vect.size() / 2);
	for (size_t i = 0; i < vect.size(); i += 2)
		vectorPair.emplace_back(vect[i], vect[i + 1]);
	for (size_t i = 0; i < vectorPair.size(); i++)
	{
		if (vectorPair[i].first < vectorPair[i].second)
			std::swap(vectorPair[i].first, vectorPair[i].second);
	}
	vect.clear();
	return (struggler);
}

void	PmergeMe::sortReverseVector(VectorP &vectorPair, int left, int right)
{
	int	middle;
	
	if (left >= right)
		return;
	middle = left + (right - left) / 2;
	sortReverseVector(vectorPair, left, middle);
	sortReverseVector(vectorPair, middle + 1, right);
	mergeVector(vectorPair, left, middle, right);
}

void	PmergeMe::mergeVector(VectorP &vectorPair, int left, int middle, int right)
{
	VectorP leftSub(vectorPair.begin() + left, vectorPair.begin() + middle + 1);
	VectorP rightSub(vectorPair.begin() + middle + 1, vectorPair.begin() + right + 1);
	size_t	i = 0;
	size_t	j = 0;
	int		k;

	k = left;
	while (i < leftSub.size() && j < rightSub.size())
	{
		if (leftSub[i].first <= rightSub[j].first)
			vectorPair[k++] = leftSub[i++];
		else
			vectorPair[k++] = rightSub[j++];
	}
	while (i < leftSub.size())
		vectorPair[k++] = leftSub[i++];
	while (j < rightSub.size())
		vectorPair[k++] = rightSub[j++];
}

void	PmergeMe::insertionVector(VectorP &vectorPair, std::vector<int> &vect)
{
	std::vector<int>::iterator	it;
	bool						ready;
	int							round;
	int							last_index;
	int							save_index;
	int							i;

	vect.push_back(vectorPair[0].second);
	for (size_t i = 0; i < vectorPair.size(); i++)
		vect.push_back(vectorPair[i].first);
	round = 3;
	ready = false;
	last_index = 0;
	i = 0;
	while (ready == false)
	{
		i = generateJacobsthalNr(round);
		round++;
		save_index = i;
		if (i >= static_cast<int>(vectorPair.size()) - 1)
		{
			i = vectorPair.size() - 1;
			ready = true;
		}
		while (i > last_index)
		{
			it = std::lower_bound(vect.begin(), vect.end(), vectorPair[i].second);
			vect.insert(it, vectorPair[i].second);
			i--;
		}
		last_index = save_index;
	}
}

// DEQUE
void	PmergeMe::sortDeque(std::deque<int> &deq)
{
	std::deque<int>::iterator	it;
	DequeP						deqPair;
	bool						struggler;

	if (deq.empty() || deq.size() == 1)
		return ;
	struggler = makePairsDeque(deqPair, deq);
	sortReverseDeque(deqPair, 0, deqPair.size() - 1);
	insertionDeque(deqPair, deq);
	if (struggler)
	{
		it = std::lower_bound(deq.begin(), deq.end(), this->struggler_);
		if (it == deq.end())
			deq.push_back(this->struggler_);
		else
			deq.insert(it, this->struggler_);
	}
}

bool	PmergeMe::makePairsDeque(DequeP &dequePair, std::deque<int> &deq)
{
	bool	struggler;

	struggler = false;
	if (deq.size() % 2 != 0)
	{
		struggler = true;
		this->struggler_ = deq[deq.size() - 1];
		deq.pop_back();
	}
	for (size_t i = 0; i < deq.size(); i += 2)
		dequePair.emplace_back(deq[i], deq[i + 1]);
	for (size_t i = 0; i < dequePair.size(); i++)
	{
		if (dequePair[i].first < dequePair[i].second)
			std::swap(dequePair[i].first, dequePair[i].second);
	}
	deq.clear();
	return (struggler);
}

void	PmergeMe::sortReverseDeque(DequeP &dequePair, int left, int right)
{
	int	middle;
	
	if (left >= right)
		return;
	middle = left + (right - left) / 2;
	sortReverseDeque(dequePair, left, middle);
	sortReverseDeque(dequePair, middle + 1, right);
	mergeDeque(dequePair, left, middle, right);
}

void	PmergeMe::mergeDeque(DequeP &dequePair, int left, int middle, int right)
{
	DequeP leftSub(dequePair.begin() + left, dequePair.begin() + middle + 1);
	DequeP rightSub(dequePair.begin() + middle + 1, dequePair.begin() + right + 1);
	size_t	i = 0;
	size_t	j = 0;
	int		k;

	k = left;
	while (i < leftSub.size() && j < rightSub.size())
	{
		if (leftSub[i].first <= rightSub[j].first)
			dequePair[k++] = leftSub[i++];
		else
			dequePair[k++] = rightSub[j++];
	}
	while (i < leftSub.size())
		dequePair[k++] = leftSub[i++];
	while (j < rightSub.size())
		dequePair[k++] = rightSub[j++];
}

void	PmergeMe::insertionDeque(DequeP &dequePair, std::deque<int> &deq)
{
	std::deque<int>::iterator	it;
	bool						ready;
	int							round;
	int							last_index;
	int							save_index;
	int							i;

	deq.push_back(dequePair[0].second);
	for (size_t i = 0; i < dequePair.size(); i++)
		deq.push_back(dequePair[i].first);
	round = 3;
	ready = false;
	last_index = 0;
	i = 0;
	while (ready == false)
	{
		i = generateJacobsthalNr(round);
		round++;
		save_index = i;
		if (i >= static_cast<int>(dequePair.size()) - 1)
		{
			i = dequePair.size() - 1;
			ready = true;
		}
		while (i > last_index)
		{
			it = std::lower_bound(deq.begin(), deq.end(), dequePair[i].second);
			deq.insert(it, dequePair[i].second);
			i--;
		}
		last_index = save_index;
	}
}

// Add numbers to container
std::chrono::duration<double>	PmergeMe::addNumbersVector(int argc, char **argv, std::vector<int> &vect)
{
	std::chrono::high_resolution_clock::time_point	start;
	std::chrono::high_resolution_clock::time_point	end;
	int	nr;
	int	j;

	start = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && !std::isdigit(argv[i][j]))
				throw wrongChar();
			if (argv[i][j] != ' ')
			{
				nr = checkLenNumber(argv[i], j);
				vect.push_back(nr);
				if (argv[i][j] == '\0')
					break ;
			}
			j++;
		}
	}
	end = std::chrono::high_resolution_clock::now();
	return (std::chrono::duration_cast<std::chrono::duration<double>>(end - start));
}

std::chrono::duration<double>	PmergeMe::addNumbersDeque(int argc, char **argv, std::deque<int> &deq)
{
	std::chrono::high_resolution_clock::time_point	start;
	std::chrono::high_resolution_clock::time_point	end;
	int	nr;
	int	j;

	start = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && !std::isdigit(argv[i][j]))
				throw wrongChar();
			if (argv[i][j] != ' ')
			{
				nr = checkLenNumber(argv[i], j);
				deq.push_back(nr);
				if (argv[i][j] == '\0')
					break ;
			}
			j++;
		}
	}
	end = std::chrono::high_resolution_clock::now();
	return (std::chrono::duration_cast<std::chrono::duration<double>>(end - start));
}

// Exceptions
const char *PmergeMe::tooHighNumber::what() const noexcept
{
	return ("Number is bigger than INT_MAX");
}

const char *PmergeMe::wrongChar::what() const noexcept
{
	return ("Input contains wrong char of '-' sign"); 
}
