#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <iterator>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_span;
		int					_addedNumbers;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& toCopy);
		~Span(void);

		Span&		operator=(const Span& copy);
		int			getN(void) const;
		int			getAddedNumbers(void) const;
		void		addNumber(int nr);
		int		 	shortestSpan(void);
		int			longestSpan(void);
		void		addNumbers(std::vector<int> range);

		class SpanIsFull : public std::exception { const char* what() const noexcept override; };
		class NotEnoughNr : public std::exception { const char* what() const noexcept override;};
};

#endif