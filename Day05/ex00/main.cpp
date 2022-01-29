#include "Bureaucrat.hpp"

int main()
{
  Bureaucrat bb("God", 45);
  Bureaucrat nn(bb);

      std::cout << bb << std::endl;
      std::cout << nn << std::endl;

      nn = (Bureaucrat("yyy", 5));

      std::cout << nn << std::endl;

    std::cout << "-------------" << std::endl;

  try
  {
      Bureaucrat bur("Gosha", 150);
      std::cout << bur << std::endl;
      bur.DecrementGrade();
      std::cout << bur << std::endl;
  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }

  std::cout << "-------------" << std::endl;

  try {
      Bureaucrat bur("Gosha", 1);
      std::cout << bur << std::endl;
      bur.IncrementGrade();
      std::cout << bur << std::endl;
  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }

  std::cout << "-------------" << std::endl;

  try {
      Bureaucrat bur("Gosha", -50);
      std::cout << bur << std::endl;
      bur.IncrementGrade();
      std::cout << bur << std::endl;
  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }

    std::cout << "-------------" << std::endl;

  try {
      Bureaucrat bur("Gosha", 50);
      std::cout << bur << std::endl;
      bur.DecrementGrade();
      std::cout << bur << std::endl;
  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }

}