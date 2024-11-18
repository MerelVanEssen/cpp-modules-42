/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:12:15 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/31 13:05:05 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base	*generate(void)
{
	int		random_nr;

	random_nr = std::rand() % 3;
	std::cout << "Random generator choose: " << random_nr << std::endl;
	switch (random_nr)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (new A());
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "No type found" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	std::cout << "No type found" << std::endl;
	return ;
}

int	main(void)
{
	std::srand(std::time(nullptr));
	{
		std::cout << GRE "Test random pointer:" RES << std::endl;
		Base	*object1;

		object1 = generate();
		std::cout << "Object: ";
		identify(object1);
		delete object1;
	}
	{
		std::cout << GRE "Test reference:" RES << std::endl;
		A		a;
		B		b;
		C		c;

		std::cout << "Object A: ";
		Base&	objectA = a;
		identify(&objectA);
		std::cout << "Object B: ";
		Base&	objectB = b;
		identify(&objectB);
		std::cout << "Object C: ";
		Base&	objectC = c;
		identify(&objectC);

	}
	{
		std::cout << GRE "Wrong class:" RES << std::endl;
		Base	*unknown = new Base();

		identify(unknown);
		delete unknown;
	}
	return (0);
}