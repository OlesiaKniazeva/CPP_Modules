#include "MateriaSource.hpp"

void MateriaSource::DeleteAllMaterias() {
 for (int i = 0; i < 4; ++i) {
    delete materias_[i];
  }
}

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    materias_[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  DeleteAllMaterias();
  std::cout << "delete MateriaSources" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
  for (int i = 0; i < 4; ++i) {
    if (rhs.materias_[i]) {
      materias_[i] = rhs.materias_[i]->clone();
    }
    else {
      materias_[i] = NULL;
    }
  }
}

MateriaSource & MateriaSource::operator=(const MateriaSource& rhs) {
  DeleteAllMaterias();
  for (int i = 0; i < 4; ++i) {
    if (rhs.materias_[i]) {
      materias_[i] = rhs.materias_[i]->clone();
    }
    else {
      materias_[i] = NULL;
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* src) {
  for (int i = 0; i < 4; ++i) {
    if (!materias_[i]) {
      materias_[i] = src;
      break ;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
  for (int i = 0; i < 4; ++i) {
    if (materias_[i] && (type == materias_[i]->getType()))
      return materias_[i]->clone();
    }
  return NULL;
}