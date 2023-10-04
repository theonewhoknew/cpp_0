#include <iostream>
#include <iomanip>
#include <ctime>
#include "../inc/Account.hpp"

int Account::_totalAmount;
int Account::_nbAccounts;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{	
	static int index;

	this->_amount = initial_deposit;
	this->_accountIndex = index;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	this->_displayTimestamp();
	std::cout << "index:" << index << ";";
	std::cout <<"amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	index++;

}

Account::~Account(void)
{	
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout <<"amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;

}

void Account::_displayTimestamp(void)
{	
	std::time_t t = std::time(NULL);
	std::tm* nowStruct = std::localtime(&t);
	int year = nowStruct->tm_year + 1900;
	int month = nowStruct->tm_mon + 1;
	int day = nowStruct->tm_mday;
	int hour = nowStruct->tm_hour;
	int min = nowStruct->tm_min;
	int sec = nowStruct->tm_min;

	std::cout << "[";
	std::cout << year;
	std::cout << std::setfill('0') << std::setw(2) << month;
	std::cout << std::setfill('0') << std::setw(2) << day;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << hour;
	std::cout << std::setfill('0') << std::setw(2) << min;
	std::cout << std::setfill('0') << std::setw(2) << sec;
	std::cout << "] ";
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{	
	int previous = 0;

	previous = this->_amount;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << previous << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{	
	int previous = 0;

	previous = this->_amount;
	if (withdrawal < this->_amount)
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << previous << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{	
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << previous << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
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