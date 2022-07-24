#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(std::string type);
    virtual ~WrongCat();
    WrongCat(const WrongCat &wrongcat);
    WrongCat &operator=(const WrongCat &wrongcat);
    virtual void makeSound() const;
};
#endif // !WRONGCAT_HPP