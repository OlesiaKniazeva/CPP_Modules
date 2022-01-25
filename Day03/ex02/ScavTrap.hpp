#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

  public:
    ScavTrap(const std::string & name);
    ScavTrap(const ScavTrap & rhs);
    ~ScavTrap();

    ScavTrap& operator=(ScavTrap const & rhs);

    void guardGate();

  protected:
    ScavTrap();

  private:
    void SetDefaultPoints();


};

#endif