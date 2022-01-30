#include "Cat.hpp"

Cat::Cat() : brain_(new Brain) {
  Animal::type_ = "Cat";
  std::cout << "I am cat" << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat is gone" << std::endl;
  delete brain_;
}

Cat::Cat(const Cat& rhs) {
 brain_ = new Brain();
  for (int i = 0; i < 100; ++i) {
    std::string idea = rhs.GetIdea(i + 1);
    brain_->SetIdea(idea, i + 1);
  }
}

Cat & Cat::operator=(const Cat& rhs) {
  delete brain_;
  brain_ = new Brain();
  for (int i = 0; i < 100; ++i) {
    std::string idea = rhs.GetIdea(i + 1);
    brain_->SetIdea(idea, i + 1);
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "May" << std::endl;
}

const std::string Cat::GetIdea(const int index) const {
  return (brain_->GetIdea(index));
}

void  Cat::SetIdea(std::string& idea, int index) {
  brain_->SetIdea(idea, index);
}