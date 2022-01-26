#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
  FragTrap Scott("Scott");
  ScavTrap Pol("Pol");
  Scott.highFivesGuys();

  Scott.attack(Pol.getTrapName());
  Pol.takeDamage(Scott.getAttackDamage());

  Scott.attack(Pol.getTrapName());
  Pol.takeDamage(Scott.getAttackDamage());

  Scott.attack(Pol.getTrapName());
  Pol.takeDamage(Scott.getAttackDamage());

  Pol.beRepaired(40);
}