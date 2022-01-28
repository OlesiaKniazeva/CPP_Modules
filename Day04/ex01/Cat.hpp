#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat();
		~Cat();
    Cat(const Cat& rhs);
    Cat & operator=(const Cat& rhs);

    virtual void makeSound() const;

    virtual const std::string GetIdea(const int index) const;
    virtual void  SetIdea(std::string& idea, int index);

    private:
      Brain * brain_;
};

#endif