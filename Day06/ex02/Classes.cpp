#include "Classes.hpp"

Base::~Base() {
}

Base * generate(void) {
  srand(static_cast<unsigned int>(time(0)));
  int num = rand() % 3;
    if (num == 1) {
       std::cout << "I return A class" << std::endl;
       return new A;
    }
    else if (num == 2) {
      std::cout << "I return B class" << std::endl;
      return new B;
    }
    else {
      std::cout << "I return C class" << std::endl;
      return new C;
    }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "This is class A pointer" << std::endl;
  }
  else if (dynamic_cast<B*>(p)) {
    std::cout << "This is class B pointer" << std::endl;
  }
  else if (dynamic_cast<C*>(p)) {
    std::cout << "This is class C pointer" << std::endl;
  }
}

void identify(Base& p) {
  try {
    A & aRef = dynamic_cast<A&>(p);
    (void)aRef;
    std::cout << "This is class A reference" << std::endl;
  }
  catch (std::bad_cast & e) {}

  try {
    B & bRef = dynamic_cast<B&>(p);
    (void)bRef;
    std::cout << "This is class B reference" << std::endl;
  }
  catch (std::bad_cast & e) {}

  try {
    C & cRef = dynamic_cast<C&>(p);
    (void)cRef;
    std::cout << "This is class C reference" << std::endl;
  }
  catch (std::bad_cast & e) {}
}