#include "ClapTrap.hpp"

int main()
{
  ClapTrap Bob("Bob");
  ClapTrap Smith("Smith");

  Bob.attack(Smith.getTrapName());
  Smith.takeDamage(Bob.getAttackDamage());
  Smith.beRepaired(10);

}