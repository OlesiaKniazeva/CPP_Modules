#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
  try
  {
    Bureaucrat Bob("Bob", 140);
    // Bureaucrat Low_worker("Low_worker", 151);
    Bureaucrat Low_worker2("Low_worker", 150);
    Bureaucrat Tom("Tom", 40);
    Bureaucrat Job("Job", 26);
    Bureaucrat Mod("Mod", 1);

    ShrubberyCreationForm Iva("Iva");
    ShrubberyCreationForm Nok("Nok");
    PresidentialPardonForm President("President");
    RobotomyRequestForm robotomy("robotomy");


    Bob.signForm(Iva);
    Tom.executeForm(Iva);
    Low_worker2.executeForm(Iva);
    // Iva.beSigned(Low_worker2);
    Tom.executeForm(President);
    Job.signForm(President);
    Job.IncrementGrade();
    Job.signForm(President);
    Job.executeForm(President);
    Mod.executeForm(President);

    Tom.signForm(robotomy);
    Mod.executeForm(robotomy);

  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }
}