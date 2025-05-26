/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:24:21 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/26 17:11:12 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/// @brief Initializes static member variables.
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/// @brief Constructs an account with an initial deposit.
/// @param initial_deposit The initial amount deposited into the account.
Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "created" << std::endl;
}

/// @brief Default constructor (unused in this context).
Account::Account(void){}

/// @brief Destructor. Logs the closing of the account.
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "closed" << std::endl;
	return ;
}

/// @brief Gets the total number of accounts.
/// @return Number of accounts created.
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

/// @brief Gets the total amount across all accounts.
/// @return Total amount.
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

/// @brief Gets the total number of deposits across all accounts.
/// @return Number of deposits.
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

/// @brief Gets the total number of withdrawals across all accounts.
/// @return Number of withdrawals.
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/// @brief Displays global account statistics.
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

/// @brief Performs a deposit on the account.
/// @param deposit The amount to deposit.
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	return ;
}

/// @brief Performs a withdrawal from the account.
/// @param withdrawal The amount to withdraw.
/// @return True if the withdrawal was successful, false otherwise.
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused"<< std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

/// @brief Returns the current account balance.
/// @return The account balance.
int		Account::checkAmount(void) const
{
	return (_amount);
}

/// @brief Displays the current account status.
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:"<< _nbWithdrawals << std::endl;
	return ;
}

/// @brief Displays a timestamp in the format [YYYYMMDD_HHMMSS].
void	Account::_displayTimestamp(void)
{
	time_t		raw_time;
	struct tm	*time_info;
	char		buffer[32];

	time(&raw_time);
	time_info = localtime(&raw_time);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", time_info);
	std::cout << buffer;
	return ;
}
