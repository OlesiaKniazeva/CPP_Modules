#include "ClapTrap.hpp"

int main()
{
  ClapTrap Bob("Bob");
  ClapTrap Smith("Smith");

  Bob.attack("Smith");
  Smith.beRepaired(6);
  Bob.takeDamage(5);
  Bob.takeDamage(5);
}