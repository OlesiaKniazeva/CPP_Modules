#include "DiamondTrap.hpp"

int main()
{
  DiamondTrap Scott("Scott");
  Scott.whoAmI();

  Scott.attack("Bob");
  Scott.highFivesGuys();
  Scott.guardGate();
  Scott.beRepaired(50);
  Scott.takeDamage(200);
}