#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

  public:
    FragTrap(const std::string& name);
    ~FragTrap();
    FragTrap(const FragTrap & rhs);

    FragTrap& operator=(const FragTrap & rhs);

    void highFivesGuys();

    protected:
      FragTrap();

    private:
      void SetDefaultPoints();

};

#endif