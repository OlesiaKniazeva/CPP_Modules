#ifndef CLASSES_HPP
# define CLASSES_HPP

#include <ctime>
#include <iostream>
#include <exception>
#include <typeinfo>
#include <cstdlib>

class Base {
  public:
    virtual ~Base();
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

Base * generate(void);

void identify(Base* p);
void identify(Base& p);

#endif