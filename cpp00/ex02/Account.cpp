/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:06:35 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/04/18 12:20:39 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>

#define	BLUE	"\033[34m"
#define	RESET	"\033[0m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int	index = 0;

	this->_accountIndex = index;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" BLUE << this->_accountIndex;
	std::cout << RESET ";amount:" BLUE << this->_amount << RESET;
	std::cout << RESET ";created" << std::endl;
	index++;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" BLUE << this->_accountIndex;
	std::cout << RESET ";amount:" BLUE << this->_amount << RESET;
	std::cout << RESET ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	int	accounts;

	accounts = getNbAccounts();
	Account::_displayTimestamp();
	std::cout << "accounts:" BLUE << accounts << ";";;
	std::cout << RESET "total:" BLUE << getTotalAmount() << ";";;
	std::cout << RESET "deposits:" BLUE << getNbDeposits() << ";";;
	std::cout << RESET "withdrawals:" BLUE << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << RESET "index:" BLUE << _accountIndex << ";";;
	std::cout << RESET "p_amount:" BLUE << this->_amount << ";";;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << RESET "deposits:" BLUE << deposit << ";";;
	std::cout << RESET "p_amount:" BLUE << this->_amount << ";";;
	std::cout << RESET "nb_deposits:" BLUE << "1" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << RESET "index:" BLUE << _accountIndex << ";";
	std::cout << RESET "p_amount:" BLUE << this->_amount << ";";
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << RESET "withdrawal:" BLUE << withdrawal << ";";
		std::cout << RESET "p_amount:" BLUE << this->_amount << ";";
		std::cout << RESET "nb_withdrawals:" BLUE << "1" << std::endl;
		return (true);
	}
	std::cout << RESET "refused" << std::endl;
	return (false);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << RESET "index:" BLUE << _accountIndex;
	std::cout << RESET ";amount:" BLUE << this->_amount;
	std::cout << RESET ";deposits:" BLUE << this->_nbDeposits;
	std::cout << RESET ";withdrawals:" BLUE << this->_nbWithdrawals << std::endl;
}

/**
 * @brief shows the data and time in YYYYMMDD_HHMMSS
*/
void	Account::_displayTimestamp(void)
{
	std::time_t	now_time_t;
	std::tm		now_tm;
	
	now_time_t = std::time(nullptr);
	now_tm = *std::localtime(&now_time_t);
	std::cout << RESET "[";
	std::cout << std::put_time(&now_tm, "%Y%m%d_%H%M%S");
	std::cout << "] ";
}

Account::Account(void)
{
}
