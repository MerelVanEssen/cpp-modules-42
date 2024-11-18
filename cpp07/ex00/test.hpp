/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:38:15 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/09/02 07:22:24 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>

class test
{
private:
	int	_nr;
public:
	test(void);
	test(int nr);
	test(const test& toCopy);
	~test(void);

	test		operator=(const test& toCopy);
	
	void		setNr(int nr);
	const int&	getNr(void) const;
	bool 		operator<(const test& tester) const;
	bool 		operator>(const test& tester) const;
};

std::ostream&	operator<<(std::ostream& os, const test& toPrint);

#endif