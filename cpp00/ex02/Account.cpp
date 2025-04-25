/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:24:21 by mariaoli          #+#    #+#             */
/*   Updated: 2025/04/25 18:18:13 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit)
{
	(void)initial_deposit;
}

Account::Account(void)
{
	return ;
}

Account::~Account(void)
{
	return ;
}

int	Account::getNbAccounts(void)
{
	return (1);
}
int	Account::getTotalAmount(void)
{
	return (1);
}
int	Account::getNbDeposits(void)
{
	return (1);
}
int	Account::getNbWithdrawals(void)
{
	return (1);
}
void	Account::displayAccountsInfos(void)
{
	
	return ;
}

void	Account::makeDeposit(int deposit)
{
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	return (false);
}
int		Account::checkAmount(void) const
{
	return (1);
}

void	Account::displayStatus(void) const
{
	return ;
}


void	Account::_displayTimestamp(void)
{
	return ;
}