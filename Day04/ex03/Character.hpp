#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
  public:

    Character(const std::string name);
    virtual ~Character();

    Character(const Character& rhs);
    Character & operator=(const Character & rhs);

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    private:
      std::string name_;
      AMateria* type_[4];
      void DeleteAllMaterias();
      
};

#endif