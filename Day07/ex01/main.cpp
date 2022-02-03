#include "iter.hpp"
#include <iostream>

template <typename T>
void multiple_to_6(T & x) {
  x *= 6;
}

template <typename T>
void add_five(T & x) {
  x += 5;
}

template <typename T>
void print_data(T & x) {
  std::cout << x << " ";
}

void add_to_str(std::string & x) {
  x += "cococo..";
}

int main()
{
  {
    int arr[6] = {1, 2, 3, 4, 5, 6};

    iter(arr, 6, print_data);
    std::cout << std::endl;
    iter(arr, 6, add_five);
    iter(arr, 6, print_data);
    std::cout << std::endl;
  }
  {
    double arr[5] = {1.1, 2.3, 5.6, -6.7, -123.5};
    iter(arr, 5, print_data);
    std::cout << std::endl;
    iter(arr, 5, multiple_to_6);
    iter(arr, 5, print_data);
    std::cout << std::endl;
  }
  {
    std::string arr[4] = { "abc", "cat", "boil", "object"};
    iter(arr, 4, print_data);
    std::cout << std::endl;
    iter(arr, 4, add_to_str);
    iter(arr, 4, print_data);
    std::cout << std::endl;
  }

}