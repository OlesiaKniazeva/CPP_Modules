#include "DiamondTrap.hpp"

void DiamondTrap::SetDefaultPoints()
{
  hitpoints_ = FragTrap::hits_;
  energy_points_ = ScavTrap::energy_;
  attack_damage_ = FragTrap::damage_;
  std::cout << "\033[35m    It has: " << hitpoints_ << " hitpoints, "
            << energy_points_ << " energy points" << std::endl
            << "    It can cause: " << attack_damage_
            << " points of damage \033[39m" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name_(name)
{
  std::cout << "DiamondTrap " << name_ << " is created" << std::endl;
  SetDefaultPoints();
}

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name_("No_name")
{
  ClapTrap::name_ = name_ + "_clap_name";
  std::cout << "Default DiamondTrap constructor created" << std::endl;
  SetDefaultPoints();
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap " << name_ << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
{
  *this = rhs;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
  name_ = rhs.name_;
  hitpoints_ = rhs.FragTrap::hitpoints_;
  energy_points_ = rhs.ScavTrap::energy_points_;
  attack_damage_ = rhs.FragTrap::attack_damage_;
  return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
  std::cout << "\033[92m    My name: " << name_
            << ", My ClapTrap name: " << ClapTrap::name_
            << "\033[39m" << std::endl;
}