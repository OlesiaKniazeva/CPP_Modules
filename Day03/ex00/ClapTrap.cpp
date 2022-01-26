#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
 name_("No_name"), hitpoints_(10),
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
  if (energy_points_ <= 0 || hitpoints_ <= 0) {
    if (energy_points_ <= 0) {
      std::cout << "ClapTrap " << name_ << " has no energy points"
                << " to attack" << std::endl;
    }
    if (hitpoints_ <= 0) {
      std::cout << "ClapTrap " << name_ << " has no hitpoints"
                << " to attack" << std::endl;
    }
  }
  else {
    std::cout << "ClapTrap " << name_ << " attack " << target
              << ", causing " << attack_damage_ << " points of damage!"
              << std::endl;
    energy_points_--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  hitpoints_ -= amount;
  std::cout << "ClapTrap " << name_ << " damaged to " << amount
            << " points" << std::endl;
  if (hitpoints_ <= 0) {
    std::cout << "\033[31m    It has no more hitpoints\033[39m" << std::endl;
  }
  else {
    std::cout << "\033[33m    Now it has: " << hitpoints_
      << " hitpoints\033[39m" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energy_points_ <= 0) {
    std::cout << "ClapTrap " << name_ << " has no energy points"
              << " to repair itself" << std::endl;
  }
  else {
  energy_points_--;
  hitpoints_ += amount;
    std::cout << "ClapTrap " << name_ << " received " << amount
              << " hitpoints back" << std::endl
              << "\033[33m    Now it has: " << hitpoints_
              << " hitpoints\033[39m" << std::endl;
  }
}

const int& ClapTrap::getHitPoints() {
  return (hitpoints_);
}

const int& ClapTrap::getEnergyPoints() {
  return (energy_points_);
}

const int& ClapTrap::getAttackDamage() {
  return (attack_damage_);
}

const std::string & ClapTrap::getTrapName() {
  return (name_);
}