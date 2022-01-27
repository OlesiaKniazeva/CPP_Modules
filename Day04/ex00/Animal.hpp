#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{

	public:

		virtual ~Animal();
    Animal(const Animal & rhs);
    Animal& operator=(const Animal & rhs);
    Animal();

    const std::string & getType() const;
    virtual void makeSound() const;


	protected:

    std::string type_;

};

#endif