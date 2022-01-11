#include "Weapon.hpp"

Weapon::Weapon( const std::string& weapon ) : weapon_(weapon) {
}

const std::string& Weapon::getType( void ) const {
  return (weapon_);
}

void Weapon::setType( const std::string& weapon_type ) {
  weapon_ = weapon_type;
}