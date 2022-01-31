#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
  try
  {
    Intern  someRandomIntern;
    Form*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Form* president;
    president = someRandomIntern.makeForm("presidental pardon", "PR");
    Form *shrubbery;
    shrubbery = someRandomIntern.makeForm("shrubbery creation", "sh");
    Form* wrong_f;
    wrong_f = someRandomIntern.makeForm("come", "home");

    delete rrf;
    delete president;
    delete shrubbery;
    delete wrong_f;
  }

  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }
}