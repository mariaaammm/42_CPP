#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void){}
Account::Account(int initial_deposit) 
{
    _displayTimestamp();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _nbAccounts++ ;
    _totalAmount += initial_deposit ;
    std::cout << "index:" << _accountIndex << ";" <<"amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
     std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}

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
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" ;
    std::cout << "total:" << _totalAmount << ";" ;
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";";
    _totalNbDeposits++;
    _nbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";" << "amount:" << _amount ;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:"/* << withdrawal << ";"*/;
    if (_amount < withdrawal)
    {
       std::cout << "refused" << std::endl;
       return (false);
    }
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << withdrawal << ";" << "amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << checkAmount() << 
        ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t tm = time(NULL);

    struct tm *p_local = localtime(&tm);
    std::cout << "[" << p_local->tm_year + 1900;
    std::cout << "0" << p_local->tm_mon + 1;
    std::cout << p_local->tm_mday << "_";
    std::cout << p_local->tm_hour ;
    std::cout << p_local->tm_min;
    std::cout << p_local->tm_sec << "] ";
}