#include "Bureaucrat.hpp"

int main()
{
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