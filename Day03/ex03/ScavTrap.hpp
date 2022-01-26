#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

  public:
    ScavTrap(const std::string & name);
    ScavTrap(const ScavTrap & rhs);
    virtual ~ScavTrap();

    ScavTrap& operator=(ScavTrap const & rhs);

    void guardGate();

  protected:
    ScavTrap();
    int hits_;
    int energy_;
    int damage_;

  private:
    void SetDefaultPoints();


};

#endif