/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:17:21 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/11/01 18:25:30 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_nbAccounts = _nbAccounts + 1;
	_amount = initial_deposit;
	_totalAmount = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << \
	initial_deposit << ";" << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << \
	";" << "closed" << std::endl;
}

int		Account::checkAmount(void) const
{
	return(_amount);
}

// DISPLAY

void	Account::_displayTimestamp( void )
{
	std::time_t time;

	time = std::time(NULL);
	std::tm *cur_time = std::localtime(&time);
	std::cout << "[" << 1900 + cur_time->tm_year << 1 << cur_time->tm_mon \
	<< cur_time->tm_mday << "_" << cur_time->tm_hour << cur_time->tm_min \
	<< cur_time->tm_sec << "]";
	
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << \
	getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";" \
	<< "withdrawals:" << getNbAccounts() << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << \
	";" << "deposits" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals \
	<<  std::endl;
}


// MAKE

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<  "p_amount:" << _amount \
	<< ";" << "deposit:" << _nbDeposits << ";" << "amount:" << \
	_amount + deposit << ";" << "nb_deposits:" << std::endl;
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<  "p_amount:" << _amount \
	<< ";" << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";" << "amount:" << _amount - withdrawal \
	<< ";" << "nb_withdrawals:" << _totalNbWithdrawals << std::endl;
	_amount = _amount + withdrawal;
	_totalAmount = _totalAmount + withdrawal;
	return (true);
}

// GETTERS

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbDeposits);
}