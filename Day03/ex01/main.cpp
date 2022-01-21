#include "ScavTrap.hpp"

int main()
{
  ClapTrap Bob("Bob");
  ScavTrap Smith("Smith");

  Smith.guardGate();
  Smith.attack("Bob");

  Smith.beRepaired(20);

}