#include "ScavTrap.hpp"

void ScavTrap::SetDefaultPoints() {
  hitpoints_ = 100;
  energy_points_ = 50;
  attack_damage_ = 20;
   std::cout << "\033[35m    It has: " << hitpoints_ << " hitpoints, "
            << energy_points_ << " energy points" << std::endl
            << "    It can cause: " << attack_damage_
            << " points of damage \033[39m" << std::endl;
}

ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name_ << " is created" << std::endl;
    SetDefaultPoints();
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name_ << " destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & rhs) {
  *this = rhs;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
  name_ = rhs.name_;
  hitpoints_ = rhs.hitpoints_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  return (*this);
}

void ScavTrap::guardGate() {
  std::cout << "\033[36m    " << name_ << " is staying on Guard Gate\033[39m" << std::endl;
}

ScavTrap::ScavTrap() {
  std::cout << "default ScavTrap is created" << std::endl;
  SetDefaultPoints();
}