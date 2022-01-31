#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: Form(target, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & rhs)
{
  *this = rhs;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs) {
  Form::operator=(rhs);
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

  Form::CheckExecution(executor);

  std::cout << "    " << executor.GetName()
            << " was pardoned by Zaphod Beeblebrox" << std::endl;
}