#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal {
  public:
    Cat();
    Cat(std::string type);
    virtual ~Cat();
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
    virtual void makeSound() const;
};
#endif