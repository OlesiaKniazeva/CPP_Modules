#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{

	public:

		virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal & rhs);
    WrongAnimal& operator=(const WrongAnimal & rhs);
    WrongAnimal();

    const std::string & getType() const;
    void makeSound() const;


	protected:

    std::string type_;

};

#endif