#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
  public:
    Dog();
    virtual ~Dog();
    Dog(std::string name);
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);
    virtual void makeSound() const;
};
#endif // !DOG_HPP