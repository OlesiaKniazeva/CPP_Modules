#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
  public:
    ClapTrap(const std::string & name);
    ClapTrap(const ClapTrap & rhs);
    virtual ~ClapTrap();

    ClapTrap& operator=(ClapTrap const & rhs);

    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const int& getHitPoints();
    const int& getEnergyPoints();
    const int& getAttackDamage();
    const std::string & getTrapName();

  protected:
    ClapTrap();
    std::string name_;
    int hitpoints_;
    int energy_points_;
    int attack_damage_;

};


#endif