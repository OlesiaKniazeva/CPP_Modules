#include "Cure.hpp"

Cure::Cure() {
  type_ = "cure";
}

Cure::~Cure() {
    std::cout << "delete " << type_ << std::endl;
}

Cure::Cure(const Cure& rhs) {
  *this = rhs;
}

Cure& Cure::operator=(const Cure& rhs) {
  type_ = rhs.type_;
  return *this;
}

AMateria* Cure::clone() const {
  Cure *copy =  new Cure(*this);
  return copy;
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

