#include "Karen.hpp"

Karen::Karen( void ) {
  message_type[0] = &Karen::debug;
  message_type[1] = &Karen::info;
  message_type[2] = &Karen::warning;
  message_type[3] = &Karen::error;
}

void  Karen::complain( int num ) {
 for (int i = num; i < 4; i++) {
      (this->*message_type[i])();
      if (i < num)
        std::cout << std::endl;
    }
}

int FindComplainLevel(std::string level) {
    std::string type_of_message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
      if (level == type_of_message[i])
        return (i);
    }
    return (-1);
}

void  Karen::complain_filter(std::string level) {
    int num = FindComplainLevel(level);
    switch (num)
    {
      case 0:
        complain(0);
        break;
      case 1:
        complain(1);
        break;
      case 2:
        complain(2);
        break;
      case 3:
        complain(3);
        break;
      default:
        std::cout << "Some insignificant problems" << std::endl;
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
