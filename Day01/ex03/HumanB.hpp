#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
class HumanB {

  public:
    HumanB( const std::string& name );
    void  setWeapon( Weapon& new_weapon);
    void  attack( void );

  private:
    Weapon      *human_weapon_;
    std::string human_name_;

};

#endif