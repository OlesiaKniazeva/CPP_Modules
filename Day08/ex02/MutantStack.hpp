#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() {}
    ~MutantStack() {}
    MutantStack(const MutantStack& rhs) { *this = rhs; }
    MutantStack & operator=(const MutantStack& rhs) {
      this->c = rhs->c;
      return *this;
    }
    iterator begin() {
      return this->c.begin();
    }
    iterator end() {
      return this->c.end();
    }

};

#endif