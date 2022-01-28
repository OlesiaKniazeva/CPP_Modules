#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain created" << std::endl;
  for (int i = 0; i < 100; ++i) {
    ideas_[i] = "Where could be some idea " + std::to_string(i + 1);
  }
}

Brain::~Brain() {
    std::cout << "Brain destructed" << std::endl;
}

Brain::Brain(const Brain & rhs) {
  *this = rhs;
}

Brain & Brain::operator=(const Brain & rhs) {
  for (int i = 0; i < 100; ++i) {
    ideas_[i] = rhs.ideas_[i];
  }
  return (*this);
}

void  Brain::SetIdea(std::string& idea, int index) {
  if (index < 1 || index > 101) {
    std::cout << "Couldn't add idea with such index, try add idea from 1 to 100" << std::endl;
  }
  else {
    ideas_[index - 1] = idea;
  }
}

const std::string Brain::GetIdea(const int index) const {
  if (index < 1 || index > 101) {
    std::cout << "Couldn't show idea with such index, try add idea from 1 to 100" << std::endl;
    return NULL;
  }
  else {
    return ideas_[index - 1];
  }
}
