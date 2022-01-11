#include "Zombie.hpp"

void  AnnonuceHordeOfZombies(int amount_of_zombies, const Zombie* zombie_hord) {
  for (int i = 0; i < amount_of_zombies; i++) {
    zombie_hord[i].announce();
  }
}

int main()
{
  int amount_of_zombies = 5;
  Zombie *first_horde_of_zombies = zombieHorde(amount_of_zombies, "Floy");
  AnnonuceHordeOfZombies(amount_of_zombies, first_horde_of_zombies);
  delete [] first_horde_of_zombies;
  amount_of_zombies = 10;
  Zombie *second_horde_of_zombies = zombieHorde(amount_of_zombies, "Joy");
  AnnonuceHordeOfZombies(amount_of_zombies, second_horde_of_zombies);
  delete [] second_horde_of_zombies;
}