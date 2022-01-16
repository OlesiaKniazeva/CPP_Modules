#include "HumanB.hpp"

HumanB::HumanB( const std::string& name )
  : human_weapon_(NULL), human_name_(name) {
}

void  HumanB::setWeapon( Weapon& new_weapon ) {
  human_weapon_ = &new_weapon;
}

void  HumanB::attack( void ) {
  if (human_weapon_) {
    std::cout << human_name_ << " attacks with his "
              << (*human_weapon_).getType() << std::endl;
  }
  else {
    std::cout << human_name_ << " is disarmed" << std::endl;
  }
}