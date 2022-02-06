#include "Span.hpp"

Span::Span(unsigned int n) : amount_(n) {
}

Span::~Span() {
}

Span::Span(const Span & rhs) {
  *this = rhs;
}

Span & Span::operator=(const Span & rhs) {
  amount_ = rhs.amount_;
  nums_ = rhs.nums_;
  return *this;
}

void Span::addNumber(int number) {
  if (nums_.size() == amount_) {
    throw std::range_error("To much nums!");
  }
  nums_.push_back(number);
}

void Span::addNumber(std::vector<int> data) {
  if (data.size() + nums_.size() <= amount_) {
    nums_.insert(nums_.end(), data.begin(), data.end());
  }
  else {
    throw std::range_error("Vector nums is too big to add!");
  }
}

Span::Span() : amount_(0) {
}

int Span::shortestSpan() {
  if (nums_.size() == 0 || nums_.size() == 1) {
    throw std::range_error("Too little data in vector! Couldn't find ShortestSpan");
  }
  std::sort(nums_.begin(), nums_.end());
  int result = abs(nums_[1] - nums_[0]);
  for(unsigned int i = 0; i < nums_.size() - 1; ++i) {
   if (abs(nums_[i + 1] - nums_[i]) < result) {
     result = abs(nums_[i + 1] - nums_[i]);
    }
  }
  return result;
}

int Span::longestSpan() {
  if (nums_.size() == 0 || nums_.size() == 1) {
    throw std::range_error("Too little data in vector! Couldn't find LongestSpan");
  }
  std::sort(nums_.begin(), nums_.end());
  return abs(nums_.back() - nums_.front());
}


