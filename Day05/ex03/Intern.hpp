#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

enum FormType {
  ROBOTOMY,
  SHRUBBERY,
  PRESIDENTAL,
  OTHER
};

class Intern {
  public:

  Intern();
  ~Intern();
  Intern(const Intern *rhs);
  Intern & operator=(const Intern *rhs);

  Form * makeForm(const std::string name_of_form, const std::string target_of_form);

  private:
      FormType FindIndexOfForm(std::string form);
};

#endif