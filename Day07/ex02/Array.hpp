#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
  public:

  Array() : length_(0) {
    data_ = nullptr;
  }

  Array(unsigned int n) : length_(n) {
    if (n)
      data_ = new T[n];
    else {
      data_ = nullptr;
    }
  }

  Array(const Array & rhs) {
    length_ = rhs.length_;
    if (length_) {
      data_ = new T[rhs.length_];
      for (unsigned int i = 0; i < length_; ++i) {
        data_[i] = rhs.data_[i];
      }
    }
    else {
      data_ = nullptr;
    }
  }

  Array operator=(const Array & rhs) {
    delete [] data_;
    if (length_) {
      length_ = rhs.length_;
      data_ = new T[rhs.length_];
      for (unsigned int i = 0; i < length_; ++i) {
        data_[i] = rhs.data_[i];
      }
    }
    else {
      data_ = nullptr;
    }
    return *this;
  }

  T& operator[](unsigned int index) {
    try {
      if (index < 0 || index >= length_) {
        throw std::exception();
      }
    }
    catch (const std::exception& e) {
      std::cerr << "Index of you element doesn't exist" << '\n';
      exit (1);
    }
    return data_[index];
  }

  ~Array() {
    delete[] data_;
  }

  unsigned int size() {
    return (length_);
  }

  private:

  T * data_;
  unsigned int length_;

};

#endif