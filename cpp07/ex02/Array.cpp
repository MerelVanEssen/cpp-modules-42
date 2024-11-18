#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _data(nullptr), _size(0)
{
	std::cout << GRE "Constructor called, len data = 0" RES << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int len) : _size(len)
{
	this->_data = new T[len];
	std::cout << GRE "Constructor called, len data = " << len << RES << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T>& toCopy) : _data(new T[toCopy.size()]), _size(toCopy.size())
{
	for (unsigned int i = 0; i < _size; i++)
		this->_data[i] = toCopy._data[i];
	std::cout << GRE "Copy constructor called" RES << std::endl;
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_data;
	std::cout << RED "Destructor called, data deleted" RES << std::endl;
}

template<typename T>
Array<T>&	Array<T>::operator=(const T& toCopy)
{
	if (this != &toCopy)
	{
		delete[] this->_data;
		this->_size = toCopy.size();
		this->_data = new T[toCopy.size()];
		for (unsigned int i = 0; i < _size; i++)
			this->_data[i] = toCopy._data[i];
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (std::out_of_range("No valid index"));
	return (this->_data[index]);
}

template<typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw (std::out_of_range("No valid index"));
	return (this->_data[index]);
}

template<typename T>
const unsigned int&	Array<T>::size(void) const
{
	return (this->_size);
}

// template<typename T>
// std::ostream&	operator<<(std::ostream& os, const T& toPrint)
// {
// 	os << toPrint;
// 	return (os);
// }