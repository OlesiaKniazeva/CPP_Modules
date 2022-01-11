#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
class Weapon {

  public:
    Weapon( const std::string& weapon );

    const std::string& getType( void ) const;
    void setType( const std::string& weapon_type );

  private:
    std::string weapon_;

};

#endif