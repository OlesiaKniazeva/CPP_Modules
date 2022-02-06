#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
  public:
    Span(unsigned int n);
    ~Span();
    Span(const Span & rhs);
    Span & operator=(const Span & rhs);

    void addNumber(int number);
    void addNumber(std::vector<int> data);
    int shortestSpan();
    int longestSpan();

  private:
    Span();
    unsigned int amount_;
    std::vector<int> nums_;

};

#endif