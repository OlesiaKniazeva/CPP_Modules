#include "Karen.hpp"

int main(int argc, char **argv)
{
  Karen karen;
  if (argc != 2) {
    std::cout << "Enter type of message to filter:" << std::endl
              << "ERROR" << std::endl
              << "INFO" << std::endl
              << "WARNING" << std::endl
              << "DEBUG" << std::endl;
  }
}