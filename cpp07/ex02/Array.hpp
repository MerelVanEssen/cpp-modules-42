#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

template <typename T>
class Array
{
private:
	T				*_data;
	unsigned int	_size;
public:
	Array(void);
	Array(unsigned int len);
	Array(const Array<T>& toCopy);
	~Array(void);

	Array&					operator=(const T& toCopy);
	T&						operator[](unsigned int index);
	const T&				operator[](unsigned int index) const;
	const unsigned int&		size(void) const;
};

// template <typename T>
// std::ostream&	operator<<(std::ostream& os, const T& toPrint);

#endif