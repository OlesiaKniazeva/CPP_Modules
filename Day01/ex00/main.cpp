#include "Zombie.hpp"

void  make_second_zombie() {
  randomChump("Leyla");
  std::cout << "\033[2m" << "time time time 2 ..." << "\033[0m" << std::endl;
}

void  make_first_zombie() {
  Zombie newZombie("Bob");
  newZombie.announce();
}

int main()
{
  Zombie Dasha("Dasha");
  Dasha.announce();

  Zombie *Krot = newZombie("Krot");
  Krot->announce();

  make_first_zombie();

  Zombie *Leto = newZombie("Leto");
  Leto->announce();

  std::cout << "\033[2m" << "time time time 1 ..." << "\033[0m" << std::endl;
  delete Leto;

  make_second_zombie();
  delete Krot;
  std::cout << "\033[2m" << "time time time 3 ..." << "\033[0m" << std::endl;
}