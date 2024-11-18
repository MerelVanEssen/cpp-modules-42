/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:39:17 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/08/26 12:56:16 by mvan-ess         ###   ########.fr       */
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
	test(const test& toCopy);
	~test(void);

	test		operator=(const test& toCopy);
	
	void		setNr(int nr);
	const int&	getNr(void) const;
};

std::ostream&	operator<<(std::ostream& os, const test& toPrint);

#endif