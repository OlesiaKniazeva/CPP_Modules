#include "Conversion.hpp"

int main(int argc, char **argv)
{
  if (argc == 2) {
    try {
      Conversion conv(static_cast<std::string>(argv[1]));
      conv.ConvertData();
    }
    catch (std::exception & e) {
      std::cout << e.what() << std::endl;
    }
  }
  else {
    std::cout
     << "\n\033[35m Please enter one argument:"
     << " literal - char, int, float or double\033[39m\n\n"
     << "   Examples: \n"
     << "       Char literal: 'c', 'a'\n"
     << "       Int literal: 0, -42, 42\n"
     << "       Float literal: 0.0f, -4.2f, 4.2f, -inff, +inff, nanf\n"
     << "       Double literal: 0.0, -4.2, 4.2, -inf, +inf, nan\n"
    << std::endl;
  }
}