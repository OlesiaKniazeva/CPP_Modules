#include "Zombie.hpp"

Zombie::Zombie( void ) {

}

Zombie::Zombie( const std::string& name ) : zombie_name_(name) {
  std::cout << "\033[4m" << zombie_name_ << "\033[0m"
            << "\033[90m rose from the dead \033[39m" << std::endl;
}

Zombie::~Zombie( void ) {
  std::cout << "\033[4m" << zombie_name_ << "\033[0m"
      << "\033[91m Nooooooooo don't kill me! \033[39m "<< std::endl;
}

void  Zombie::announce( void ) const {
  std::cout << "\033[4m" << zombie_name_ << "\033[0m"
      << "\033[92m" << " BraiiiiiiinnnzzzZ..." << "\033[39m" << std::endl;
}