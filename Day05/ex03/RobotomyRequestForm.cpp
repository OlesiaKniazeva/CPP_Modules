#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
  Form(target, 72, 45) {

}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & rhs) {
  *this = rhs;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs) {
  Form::operator=(rhs);
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

  Form::CheckExecution(executor);

  srand(static_cast<unsigned int>(time(0)));
  std::cout << "    Drrrrrrr... Drrrrrrrrrrr..... Drrrrrrrrr......" << std::endl;
  if (rand() % 2 == 0) {
    std::cout << "    Form \"" << getTarget() << "\" has been robotomised" << std::endl;
  }
  else {
    std::cout << "    Robotomy of form \"" << getTarget() << "\" failed" << std::endl;
  }
}
