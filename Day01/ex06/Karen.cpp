#include "Karen.hpp"

void  Karen::complain( std::string level ) {
  if (level == "DEBUG") {
    debug();
  }
  if (level == "INFO") {
    info();
  }
  if (level == "WARNING") {
    info();
  }
  if (level == "ERROR") {
    error();
  }
}

void Karen::debug( void ) {
  std::cout << "[DEBUG]" << std::endl
            << "This is debug level" << std::endl;
}

void Karen::info( void ) {
  std::cout << "[INFO]" << std::endl
            << "This is info level" << std::endl;
}

void Karen::warning( void ) {
  std::cout << "[WARNING]" << std::endl
            << "This is warning level" << std::endl;
}

void Karen::error( void ) {
    std::cout << "[ERROR]" << std::endl
              << "This is error level" << std::endl;
}
