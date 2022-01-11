#include <iostream>

int main(int argc, char **argv)
{
  if (argc != 4) {
    std::cout << "\033[4mEnter filename and two strings: \033[0m" << std::endl
              << std::endl
              << "Example: \033[33m./replace FILENAME STRING STRING\033[39m" << std::endl;
    return (0);
  }
  std::string filename, s1, s2;
  filename = argv[0];
  s1 = argv[1];
  s2 = argv[2];
}