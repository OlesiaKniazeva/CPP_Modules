#include "Cat.hpp"

Cat::Cat() {
  Animal::type_ = "Cat";
  std::cout << "I am cat" << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat is gone" << std::endl;
}

Cat::Cat(const Cat& rhs) {
  *this = rhs;
}

Cat & Cat::operator=(const Cat& rhs) {
  type_ = rhs.type_;
  return (*this);
}

void Cat::makeSound() const {
  std::cout << "May" << std::endl;
}