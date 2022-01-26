#include "DiamondTrap.hpp"

int main()
{
  DiamondTrap Scott("Scott");
  Scott.whoAmI();

  ScavTrap Bob("Bob");


  Scott.attack(Bob.getTrapName());
  Bob.takeDamage(Scott.getAttackDamage());
  Scott.highFivesGuys();
  Scott.guardGate();
  Scott.beRepaired(50);
}