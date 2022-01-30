#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
  public:

    MateriaSource();
    MateriaSource(const MateriaSource& rhs);
    MateriaSource & operator=(const MateriaSource& rhs);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* src);
    virtual AMateria* createMateria(std::string const & type);

    private:

    AMateria *materias_[4];
    void DeleteAllMaterias();


};

#endif