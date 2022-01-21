#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
 name_(NULL), hitpoints_(10),
 energy_points_(10), attack_damage_(0) {
  std::cout << "default ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string & name) :
 name_(name), hitpoints_(10),
 energy_points_(10), attack_damage_(0) {
  std::cout << " ClapTrap " << name << " is created" << std::endl;
  std::cout << "\033[32m    It has: " << hitpoints_ << " hitpoints, "
            << energy_points_ << " energy points" << std::endl
            << "    It can cause: " << attack_damage_
            << " points of damage \033[39m" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name_ << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & rhs) {
  *this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap & rhs) {
  name_ = rhs.name_;
  energy_points_ = rhs.energy_points_;
  attack_damage_ = rhs.attack_damage_;
  hitpoints_ = rhs.hitpoints_;
  return *this ;
}

void ClapTrap::attack(std::string const & target) {
  std::cout << "ClapTrap" << name_ << " attack " << target
            << ", causing " << attack_damage_ << " points of damage!"
            << std::endl;
  hitpoints_--;
  if (hitpoints_ < 1) {
    std::cout << "\033[31m    No hitpoints left\033[39m" << std::endl;
  }
  else {
    std::cout << "\033[33m   Now it has: " << hitpoints_
            << " hitpoints\033[39m" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  energy_points_ -= amount;
  std::cout << "ClapTrap" << name_ << " damaged to " << amount
            << " points" << std::endl;
  if (energy_points_ < 1) {
    std::cout << "\033[31m    It has no more energy points\033[39m" << std::endl;
  }
  else {
    std::cout << "\033[33m    Now it has: " << energy_points_
      << " energy points\033[39m" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  energy_points_ += amount;
  std::cout << "ClapTrap" << name_ << " recieved " << amount
            << " energy points" << std::endl
            << "\033[33m    Now it has: " << energy_points_
            << " energy points\033[39m" << std::endl;
}