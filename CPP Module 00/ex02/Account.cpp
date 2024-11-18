#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

# define R   "\x1B[31m"
# define RESET "\x1B[0m"


int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	std::time_t t = std::time(0);
	char mbstr[100];
	if (std::strftime(mbstr, sizeof(mbstr), "[%Y%m%d_%H%M%S]", std::localtime(&t)))
		std::cout << mbstr;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->getNbAccounts();
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << R << this->_accountIndex << RESET << ";amount:" << R << this->_amount << RESET << ";created" << std::endl;
}
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << R << getNbAccounts() << RESET << ";total:" << R << getTotalAmount() << RESET << ";deposits:" << R << getNbDeposits() << RESET << ";withdrawals:" << R << getNbWithdrawals() << RESET << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << R << this->_accountIndex << RESET << ";amount:" << R << this->_amount << RESET << ";deposits:" << R << this->_nbDeposits << RESET << ";withdrawals:" << R << this->_nbWithdrawals << RESET << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << R << this->_accountIndex << RESET << ";p_amount:" << R << this->_amount - deposit << RESET << ";deposit:" << R << deposit << RESET << ";amount" << R << this->_amount << RESET << ";nb_deposits:" << R << this->_nbDeposits << RESET << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << R << this->_accountIndex << RESET << ";p_amount:" << R << this->_amount << RESET << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << R << this->_accountIndex << RESET << ";p_amount:" << R << this->_amount + withdrawal << RESET << ";withdrawal:" << R << withdrawal << RESET << ";amount" << R << this->_amount << RESET << ";nb_withdrawal:" << R << this->_nbWithdrawals << RESET << std::endl;
	return (true);
}

Account::~Account(){
	_displayTimestamp();
	std::cout << " index:" << R << this->_accountIndex << RESET << ";amount:" << R << this->_amount << RESET << ";closed" << std::endl;
}