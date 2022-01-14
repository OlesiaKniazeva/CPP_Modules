#include "Karen.hpp"

Karen::Karen( void ) {
  message_type[0] = &Karen::debug;
  message_type[1] = &Karen::info;
  message_type[2] = &Karen::warning;
  message_type[3] = &Karen::error;
}

void  Karen::complain( std::string level ) {
  std::string type_of_message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (level == type_of_message[i]) {
      (this->*message_type[i])();
      break ;
    }
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
