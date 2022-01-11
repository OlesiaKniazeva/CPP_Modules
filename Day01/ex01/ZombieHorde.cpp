#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
  Zombie *zombies = new Zombie[N];
  if (!zombies) {
    std::cout << "Couldn't allocate memory!" << std::endl;
    exit(1);
  }
  for (int i = 0; i < N; i++) {
    zombies[i].SetZombieName(name);
  }
  return (zombies);
}