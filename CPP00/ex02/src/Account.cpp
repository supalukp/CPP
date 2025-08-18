/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:01:51 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 22:47:51 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _totalAmount+= initial_deposit;
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "created" << std::endl;
    
}

Account::~Account( void )
{   
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "closed" << std::endl;
    _nbAccounts--;
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}
void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    char buf[20];
    std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", std::localtime(&now));
    std::cout << buf << " ";
}

void	Account::makeDeposit( int deposit )
{
    if (deposit <= 0)
        return ;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "p_amount:" << _amount << ";"
        << "deposit:" << deposit << ";";
    _nbDeposits++;
    _amount += deposit;
    _totalAmount+=deposit;
    _totalNbDeposits++;
    std::cout << "amount:" << _amount << ";"
        << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (_amount < withdrawal)
    {
         _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
         _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:" << withdrawal << ";";
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount-=withdrawal;
        _totalNbWithdrawals++;
        std::cout << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const 
{
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "amount:" << checkAmount() << ";"
        << "deposits:" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals << std::endl;
}
