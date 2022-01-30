#include "Form.hpp"

int main()
{
  try
  {
    Bureaucrat gleb("Gleb", 60);
    Bureaucrat anton("Anton", 1);
    Form get_money("get money", 50);
    std::cout << get_money << std::endl;
    get_money.beSigned(gleb);
    std::cout << get_money << std::endl;
    anton.signForm(get_money);
    std::cout << get_money << std::endl;

    Form to_add_data("to add data", 151);

  }
  catch(const std::exception& e)
  {
      std::cerr << e.what() << '\n';
  }
}