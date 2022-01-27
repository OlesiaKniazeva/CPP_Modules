#include "WrongCat.hpp"

WrongCat::WrongCat() {
  WrongAnimal::type_ = "WrongCat";
  std::cout << "I am WrongCat" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat is gone" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) {
  *this = rhs;
}

WrongCat & WrongCat::operator=(const WrongCat& rhs) {
  type_ = rhs.type_;
  return (*this);
}

void WrongCat::makeSound() const {
  std::cout << "May.." << std::endl;
}