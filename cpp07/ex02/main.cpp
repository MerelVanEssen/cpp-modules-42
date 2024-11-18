#include <iostream>
#include "Array.hpp"
#include "Array.cpp"

#define MAX_VAL 750

void	empty_array_test(void)
{
	std::cout << "EMPTY ARRAY" << std::endl;
	Array<int> empty_array;

	std::cout << YEL "Size empty string: " << empty_array.size() << RES << std::endl;
}

void	const_and_copy_test(void)
{
	std::cout << YEL "Making a basic array, copy constructor to a const array and than use operator" RES << std::endl;
	Array<int>	basic_array(4);

	for (unsigned int i = 0; i < basic_array.size(); i++)
		basic_array[i] = i;

	const Array<int>	const_array(basic_array);

	std::cout << "Size normal array: " << basic_array.size() << std::endl;
	std::cout << "Size const array: " << const_array.size() << std::endl;
	for (unsigned int i = 0; i < 4; i++)
	{
		std::cout << "First & const: " << (basic_array[i]) << " : " << (const_array[i]) << std::endl;
	}
}

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(nullptr));
	std::cout << YEL "Size numbers: " << numbers.size() << RES << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	// Check if the numbers are the same
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << RED "didn't save the same value!!" RES << std::endl;
			return (1);
		}
	}
	// check if the function throws an error with wrong index numbers
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	{
		std::cout << BLU "Own tests" RES << std::endl;
		empty_array_test();
		const_and_copy_test();
	}
	return (0);
}