#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return _totalAmount;
}
int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout 
	<< "index:" << getNbAccounts() 
	<< ";amount:" << this->_amount
	<< ";created\n";
	_nbAccounts++;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout 
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed\n";
	_nbAccounts--;
	_totalAmount -= _amount;
}

void Account::_displayTimestamp() {
	std::time_t now = std::time(NULL);
	std::tm *local = std::localtime((&now));
	std::cout << "[" << local->tm_year + 1900
			  << std::setw(2) << std::setfill('0') << local->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << local->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << local->tm_hour
			  << std::setw(2) << std::setfill('0') << local->tm_min
			  << std::setw(2) << std::setfill('0') << local->tm_sec
			  << "] ";
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout 
		<< "accounts:" << getNbAccounts() 
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<<std::endl;
}
bool Account::makeWithdrawal( int withdrawal ) {
	if (this->_amount - withdrawal < 0)
	{	
		_displayTimestamp();
		std::cout
			<< "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:refused"
			<< std::endl;
		return false;
	}
	else
	{
		_displayTimestamp();
		std::cout
			<< "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<<std::endl;
		return true;
	}
}
int	 Account::checkAmount( void ) const {
	return _amount;
}
