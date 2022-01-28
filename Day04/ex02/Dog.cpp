#include "Dog.hpp"

Dog::Dog() : brain_(new Brain) {
  Animal::type_ = "Dog";
	std::cout << "I am dog" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog is gone" << std::endl;
  delete brain_;
}

Dog::Dog(const Dog & rhs) {
  delete brain_;
  *this = rhs;
}

Dog & Dog::operator=(const Dog & rhs) {
  type_ = rhs.type_;
  delete brain_;
  brain_ = rhs.brain_;
  return (*this);
}

void Dog::makeSound() const {
  std::cout << "Haw" << std::endl;
}

const std::string Dog::GetIdea(const int index) const {
  return (brain_->GetIdea(index));
}

void  Dog::SetIdea(std::string& idea, int index) {
  brain_->SetIdea(idea, index);
}