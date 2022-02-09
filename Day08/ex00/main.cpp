#include "easyfind.hpp"
#include <vector>
#include <set>

void fill_set(std::set<int>& s) {
  s.insert(5);
  s.insert(550);
  s.insert(-45);
}

int main()
{
    try {
      int arr[]={9,10,5,3,2,5};
      std::vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]));
      std::cout << easyfind(v, 2) << std::endl;
      std::set<int> s;
      fill_set(s);
      std::cout << easyfind(s, 550) << std::endl;
      std::cout << easyfind(v, 20) << std::endl;

    }
    catch(const std::exception & e) {
        std::cerr << "No element in container" << std::endl;
    }
    std::cout << "------------" << '\n';
    try {
          std::vector<int> f;
          std::cout << easyfind(f, 40) << std::endl;
    }
    catch(const std::exception & e) {
          std::cerr << "No element in container" << std::endl;
    }
}