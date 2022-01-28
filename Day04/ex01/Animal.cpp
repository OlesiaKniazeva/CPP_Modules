#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
  std::cout << "I am animal" << std::endl;
}

Animal::~Animal() {
  std::cout << "Animal gone" << std::endl;
}

Animal::Animal(const Animal & rhs) {
  *this = rhs;
}

Animal& Animal::operator=(const Animal & rhs) {
  type_ = rhs.type_;
  return (*this);
}

void Animal::makeSound() const {
  std::cout << "???" << std::endl;
}

const std::string & Animal::getType() const {
  return (type_);
}