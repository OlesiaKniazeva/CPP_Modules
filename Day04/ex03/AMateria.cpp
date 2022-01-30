#include "AMateria.hpp"

AMateria::AMateria() {

}

AMateria::AMateria(std::string const & type) : type_(type) {
}

AMateria::~AMateria() {
  std::cout << "delete " << type_ << std::endl;
}

AMateria::AMateria(const AMateria& rhs) {
  *this = rhs;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
  type_ = rhs.type_;
  return (*this);
}

std::string const & AMateria::getType() const {
  return type_;
}