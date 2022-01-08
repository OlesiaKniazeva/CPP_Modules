#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
  _accountIndex = _nbAccounts++;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << " "
            << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created" << std::endl;
}

Account::~Account( void ) {
  _displayTimestamp();
  std::cout << " "
            << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed" << std::endl;
}

	int		Account::checkAmount( void ) const {
    return _amount;
  }

  void	Account::displayStatus( void ) const {
      _displayTimestamp();
       std::cout << " "
                 << "index:" << _accountIndex << ";"
                 << "amount:" << _amount << ";"
                 << "deposits:" << _nbDeposits << ";"
                 << "withdrawals:" << _nbWithdrawals
                 << std::endl;
  }

	void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << " "
              << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals()
              << std::endl;
  }

  // Если в time отправить 0,
  // то возвращает количество секунд,
  // прошедших с 1 января 1970 года
  // strftime в буфер записывает строку
  // опр. формата, извлекая данные из структуры
  void	Account::_displayTimestamp( void ) {
    time_t seconds_since_epoch = time(0);
    tm *struct_time = localtime(&seconds_since_epoch);
    char buffer[80];
    strftime(buffer, 80, "[%Y%m%d_%H%M%S]", struct_time);
    std::cout << buffer;
  }

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

  void	Account::makeDeposit( int deposit ) {
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << " "
              << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";";

    _amount += deposit;

    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits
              << std::endl;
  }

  bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << " "
              << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "withdrawal:";
    if (withdrawal > _amount) {
      std::cout << "refused" << std::endl;
      return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";"
              << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return (true);
  }

	int	Account::_nbAccounts = 0;
  int	Account::_totalAmount = 0;
  int	Account::_totalNbDeposits = 0;
  int	Account::_totalNbWithdrawals = 0;


