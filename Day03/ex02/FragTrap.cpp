#include "FragTrap.hpp"

void FragTrap::SetDefaultPoints() {
  hitpoints_ = 100;
  energy_points_ = 100;
  attack_damage_ = 30;
   std::cout << "\033[35m    It has: " << hitpoints_ << " hitpoints, "
            << energy_points_ << " energy points" << std::endl
            << "    It can cause: " << attack_damage_
            << " points of damage \033[39m" << std::endl;
}


FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap " << name_ << " is created" << std::endl;
    SetDefaultPoints();

}

FragTrap::~FragTrap() {
     std::cout << "FragTrap " << name_ << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap & rhs) {
  *this = rhs;
}

FragTrap& FragTrap::operator=(const FragTrap & rhs) {
  name_ = rhs.name_;
  hitpoints_ = rhs.hitpoints_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  return (*this);
}

void FragTrap::highFivesGuys() {
  std::cout << "\033[94mHey! I am " << name_ <<  " - take high five\033[39m" << std::endl;
}

FragTrap::FragTrap() {
  std::cout << "default FragTrap is created" << std::endl;
  SetDefaultPoints();
}