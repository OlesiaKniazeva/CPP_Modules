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
  brain_ = new Brain();
  for (int i = 0; i < 100; ++i) {
    std::string idea = rhs.GetIdea(i + 1);
    brain_->SetIdea(idea, i + 1);
  }
}

Dog & Dog::operator=(const Dog & rhs) {
  delete brain_;
  brain_ = new Brain();
  for (int i = 0; i < 100; ++i) {
    std::string idea = rhs.GetIdea(i + 1);
    brain_->SetIdea(idea, i + 1);
  }
  return *this;
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