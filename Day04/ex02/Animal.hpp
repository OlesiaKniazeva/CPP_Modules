#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:

		virtual ~Animal();
    Animal(const Animal & rhs);
    Animal& operator=(const Animal & rhs);
    Animal();

    virtual const std::string & getType() const;
    virtual void makeSound() const = 0;

    virtual const std::string GetIdea(const int index) const = 0;
    virtual void  SetIdea(std::string& idea, int index) = 0;

    std::string type_;

};

#endif