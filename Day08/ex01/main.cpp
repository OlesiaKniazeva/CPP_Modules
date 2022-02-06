#include "Span.hpp"
#include <cstdlib>

void PrintVector(std::vector<int> v) {
  unsigned int size = v.size();
  std::cout << "{ ";
  for (unsigned int i = 0; i < size; ++i) {
    std::cout << v[i] << " ";
    if (i % 20 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << "}" << std::endl;
}


std::vector<int> makeVector() {
  int arr[] = {5, 10, -6, 40, 32, -345, -32, 12, 23, 560, 1, 0, -3, 9, 20};
  std::vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]));
  return v;
}

int main() {

  {
    try {
      Span sp = Span(5);

      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);

      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
      std::cerr << "Error occurred" << "\n";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << "------------------" << std::endl;

  {
    try {
      Span sp = Span(2);
      sp.addNumber(-100);
      sp.addNumber(-500);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
      std::cerr << "Error occurred" << "\n";
      std::cout << e.what() << std::endl;
    }
  }

    std::cout << "------------------" << std::endl;

  {
    try {
      Span sp = Span(2);
      sp.addNumber(100);
      sp.addNumber(-500);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
      std::cerr << "Error occurred" << "\n";
      std::cout << e.what() << std::endl;
    }
  }

    std::cout << "------------------" << std::endl;

  {
    try {
      Span sp = Span(15);
      std::vector<int> v = makeVector();
      sp.addNumber(v);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
      std::cerr << "Error occurred" << "\n";
      std::cout << e.what() << std::endl;
    }
  }

      std::cout << "------------------" << std::endl;

  {
    try {
      Span sp = Span(20000);
      // Span sp = Span(19999);
      std::vector<int> v;
      srand(static_cast<unsigned int>(time(0)));
      for (int i = 0; i < 20000; i++) {
          if (i % 2 == 0) {
            v.push_back(rand() % 10000);
          }
          else {
            v.push_back(-rand() % 10000);
          }
      }
      // PrintVector(v);
      sp.addNumber(v);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
      std::cerr << "Error occurred" << "\n";
      std::cout << e.what() << std::endl;
    }
  }

      std::cout << "------------------" << std::endl;

  {
    try {
      Span sp = Span(10000);
      std::vector<int> v;
      for (int i = 0; i < 10000; i++) {
            v.push_back(i * 2);
      }
      // PrintVector(v);
      sp.addNumber(v);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
      std::cerr << "Error occurred" << "\n";
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}