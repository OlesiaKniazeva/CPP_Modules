#include "Character.hpp"

void Character::DeleteAllMaterias() {
  for (int i = 0; i < 4; ++i) {
    delete type_[i];
  }
}


Character::Character(const std::string name) : name_(name)
{
  for (int i = 0; i < 4; ++i) {
    type_[i] = NULL;
  }
}

Character::~Character() {
  DeleteAllMaterias();
  std::cout << "delete " << name_ << std::endl;
}

Character::Character(const Character& rhs) {
  name_ = rhs.name_;
  for (int i = 0; i < 4; ++i) {
    if (rhs.type_[i]) {
      type_[i] = rhs.type_[i]->clone();
    }
    else {
      type_[i] = NULL;
    }
  }
}

Character & Character::operator=(const Character & rhs) {
  DeleteAllMaterias();
  name_ = rhs.name_;
  for (int i = 0; i < 4; ++i) {
    if (rhs.type_[i]) {
      type_[i] = rhs.type_[i]->clone();
    }
    else {
      type_[i] = NULL;
    }
  }
  return *this;
}

std::string const & Character::getName() const {
  return name_;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; ++i) {
    if (!type_[i]) {
      type_[i] = m;
      break ;
    }
  }
}

void Character::unequip(int idx) {
  if (type_[idx]) {
    type_[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (type_[idx]) {
    type_[idx]->use(target);
  }
}