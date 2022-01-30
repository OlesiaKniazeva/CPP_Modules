#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  {
    // Animal * pop = new Dog;
    Dog bob;
    Dog bon(bob);
    
  }
      std::cout << "-------------" << std::endl;

  {
    Animal *dog = new Dog();
    std::string idea = "Wow, wow, Happy to see you!!!!";
    dog->SetIdea(idea, 1);
    std::cout << dog->GetIdea(1) << std::endl;

    Animal *cat = new Cat();
    std::string idea2 = "Myrrr, myrrrr, I want to eat";
    cat->SetIdea(idea2, 1);
    std::cout << cat->GetIdea(1) << std::endl;

    delete cat;
    delete dog;
  }

      std::cout << "-------------" << std::endl;

  {
    int amount_of_animals = 6;

    Animal *animals[amount_of_animals];

    for (int i = 0; i < amount_of_animals; ++i) {
      if (i < amount_of_animals / 2) {
        animals[i] = new Dog;
        std::string idea = "Wow, wow, Happy to see you!!!!";
        for (int h = 0; h < 100; ++h) {
          animals[i]->SetIdea(idea, h + 1);
        }
      }
      else {
        animals[i] = new Cat;
        std::string idea = "Myrrr, myrrrr, I want to eat";
        for (int h = 0; h < 100; ++h) {
            animals[i]->SetIdea(idea, h + 1);
          }
      }
    }

    std::cout << "-------------" << std::endl;

    std::cout << animals[1]->GetIdea(1) << std::endl;
    std::cout << animals[4]->GetIdea(3) << std::endl;

    std::cout << "-------------" << std::endl;

    for (int i = 0; i < amount_of_animals; ++i) {
      delete animals[i];
    }
  return 0;
  }
}