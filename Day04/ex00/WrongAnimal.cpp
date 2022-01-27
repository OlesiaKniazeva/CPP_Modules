#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
  std::cout << "I am WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal gone" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & rhs) {
  *this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal & rhs) {
  type_ = rhs.type_;
  return (*this);
}

void WrongAnimal::makeSound() const {
  std::cout << "???..." << std::endl;
}

const std::string & WrongAnimal::getType() const {
  return (type_);
}