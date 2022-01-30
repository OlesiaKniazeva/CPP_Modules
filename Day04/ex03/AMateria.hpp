#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
  public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria(const AMateria& rhs);
    AMateria& operator=(const AMateria& rhs);

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;

    virtual void use(ICharacter& target) = 0;

  protected:
    std::string type_;
    AMateria();
};

# endif