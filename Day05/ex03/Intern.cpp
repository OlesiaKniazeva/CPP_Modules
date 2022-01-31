#include "Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern *rhs) {
  *this = rhs;
}

Intern & Intern::operator=(const Intern *rhs) {
  (void) rhs;
  return (*this);
}

FormType Intern::FindIndexOfForm(std::string form) {
  const std::string forms[3] =
    {"robotomy request", "shrubbery creation", "presidental pardon"};
  int i = 0;
  while (i < 3 && form != forms[i]) {
    ++i;
  }
  return static_cast<FormType>(i);
}

Form * Intern::makeForm(const std::string name_of_form, const std::string target_of_form) {

  switch (FindIndexOfForm(name_of_form))
  {
    case ROBOTOMY:
      std::cout << "Intern creates form \"" << target_of_form << "\"" << std::endl;
      return new RobotomyRequestForm(target_of_form);

    case SHRUBBERY:
      std::cout << "Intern creates form \"" << target_of_form  << "\"" << std::endl;
      return new PresidentialPardonForm(target_of_form);

    case PRESIDENTAL:
      std::cout << "Intern creates form \"" << target_of_form  << "\"" << std::endl;
      return new ShrubberyCreationForm(target_of_form);

    default:
      std::cout << "No such type of form exist!" << std::endl
              << "  Please choose from available forms: \n"
              << "    1) robotomy request\n"
              << "    2) shrubbery creation\n"
              << "    3) presidental pardon\n";
    return NULL;
  }
}

