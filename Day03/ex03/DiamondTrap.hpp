#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
  public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap & rhs);

    DiamondTrap & operator=(const DiamondTrap & rhs);

    void whoAmI();
    void attack(std::string const & target);

  protected:
    DiamondTrap();

  private:
    std::string name_;
    void SetDefaultPoints();

};

#endif