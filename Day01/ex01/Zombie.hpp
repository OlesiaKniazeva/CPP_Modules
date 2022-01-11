#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie {

  public:

  Zombie ( void );
  Zombie( const std::string& name );
  ~Zombie( void );

  void  SetZombieName( const std::string& name );
  void announce( void ) const;

  private:

  std::string zombie_name_;
};

Zombie* zombieHorde( int N,  std::string name );

#endif