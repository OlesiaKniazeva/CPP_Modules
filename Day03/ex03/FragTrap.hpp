#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

  public:
    FragTrap(const std::string& name);
    virtual ~FragTrap();
    FragTrap(const FragTrap & rhs);

    FragTrap& operator=(const FragTrap & rhs);

    void highFivesGuys();

    protected:
      FragTrap();
      int hits_;
      int energy_;
      int damage_;

    private:
      void SetDefaultPoints();

};

#endif