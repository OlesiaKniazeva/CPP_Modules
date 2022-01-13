#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void  CheckAmountOfArgs(int argc) {
 if (argc != 4) {
    std::cerr << "\033[4mEnter filename and two strings: \033[0m" << std::endl
              << std::endl
              << "Example: \033[33m./replace FILENAME STRING STRING\033[39m" << std::endl;
    exit(1);
  }
}

void    CheckIfStringsAreEmpty(const std::string& name,
             const std::string& s1, const std::string& s2) {
   if (name.empty() || s1.empty() || s2.empty()) {
    std::cerr << "Strings shouldn't be empty!" << std::endl;
    exit(2);
  }
}

void  CheckInputForErrors(std::ifstream& input, const std::string& input_name) {
  if (!input) {
    std::cerr << "Couldn't read from file: "
              << "\033[1m" << input_name << "\033[0m" << std::endl;
    exit(3);
  }
  else if (input.peek() == EOF) {
    std::cerr << "File is empty!" << std::endl;
    input.close();
    exit(4);
  }
}

void CheckOutputForErrors(std::ofstream& output, const std::string output_name,
            std::ifstream& input) {
  if (!output) {
    std::cerr << "Couldn't write to file: "
              << "\033[1m" << output_name << "\033[0m" << std::endl;
    input.close();
    exit(5);
  }
}

int main(int argc, char **argv)
{
  CheckAmountOfArgs(argc);
  std::string input_name = argv[1];
  std::string output_name = input_name + ".replace";
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  CheckIfStringsAreEmpty(input_name ,s1, s2);
  std::ifstream input(input_name.c_str());
  CheckInputForErrors(input, input_name);
  std::ofstream output(output_name.c_str());
  CheckOutputForErrors(output, output_name, input);

  std::string get_string;
  bool find_string = false;
  while (getline(input, get_string)) {
    int i = 0;
    for (i = get_string.find(s1, i++); i != (int) std::string::npos; i = get_string.find(s1, i++)) {
      get_string.erase(i, s1.length());
      get_string.insert(i, s2);
      find_string = true;
    }
    output << get_string << std::endl;
  }
  input.close();
  output.close();
}