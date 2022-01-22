#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
  public:
    ClapTrap(const std::string & name);
    ClapTrap(const ClapTrap & rhs);
    ~ClapTrap();

    ClapTrap& operator=(ClapTrap const & rhs);

    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  protected:
    ClapTrap();
    std::string name_;
    int hitpoints_;
    int energy_points_;
    int attack_damage_;

};


#endif