#include "HumanA.hpp"

HumanA::HumanA( const std::string& name, Weapon& weapon )
  : human_weapon_(weapon), human_name_(name) {
}

const std::string& HumanA::getWeapon( void ) const {
  return (human_weapon_.getType());
}

void  HumanA::setWeapon( const Weapon& new_weapon) {
  human_weapon_ = new_weapon;
}

void  HumanA::attack( void ) {
  std::cout << human_name_ << " attacks with his "
            << getWeapon() << std::endl;
}