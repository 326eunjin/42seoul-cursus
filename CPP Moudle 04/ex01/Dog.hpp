#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {
  private:
    Brain *brain;

  public:
    Dog();
    virtual ~Dog();
    Dog(std::string name);
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);
    virtual void makeSound() const;
    Brain *getBrain() const;
};
#endif // !DOG_HPP