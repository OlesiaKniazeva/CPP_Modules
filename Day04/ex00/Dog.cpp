#include "Dog.hpp"

Dog::Dog() {
  Animal::type_ = "Dog";
	std::cout << "I am dog" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog is gone" << std::endl;
}

Dog::Dog(const Dog & rhs) {
  *this = rhs;
}

Dog & Dog::operator=(const Dog & rhs) {
  type_ = rhs.type_;
  return (*this);
}

void Dog::makeSound() const {
  std::cout << "Haw" << std::endl;
}