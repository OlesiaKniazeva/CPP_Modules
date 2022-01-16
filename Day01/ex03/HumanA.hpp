#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

  public:
    HumanA( const std::string& name, Weapon& weapon );
    void  setWeapon( const Weapon& new_weapon);
    void  attack( void );

  private:
    Weapon& human_weapon_;
    std::string human_name_;

};

#endif