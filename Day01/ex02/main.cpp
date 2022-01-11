#include <iostream>

int main()
{
  std::string str = "HI THIS IS BRAIN";

  std::string *stringPTR;
  stringPTR = &str;

  std::string &stringREF = str;

  std::cout << "Address of string by stringPTR: " << stringPTR << std::endl;
  std::cout << "Address of string by stringREF: " << &stringREF << std::endl;

  std::cout << std::endl;

  std::cout << "Value of string by stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value of string by stringREF: " << stringREF << std::endl;
}