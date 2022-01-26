#include "ScavTrap.hpp"

int main()
{
  ClapTrap Bob("Bob");
  ScavTrap Smith("Smith");

  Smith.guardGate();
  Smith.attack(Bob.getTrapName());
  Bob.takeDamage(Smith.getAttackDamage());
  Smith.beRepaired(20);
  Bob.attack(Smith.getTrapName());
  Bob.beRepaired(20);
  Bob.attack(Smith.getTrapName());
  Bob.takeDamage(Bob.getAttackDamage());

}