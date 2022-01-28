#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:

		Dog();
		~Dog();
    Dog(const Dog& rhs);
    Dog & operator=(const Dog & rhs);

    virtual void makeSound() const;

    virtual const std::string GetIdea(const int index) const;
    virtual void  SetIdea(std::string& idea, int index);

    private:
      Brain * brain_;
};

#endif