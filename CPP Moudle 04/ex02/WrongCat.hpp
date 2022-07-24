#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(std::string type);
    ~WrongCat();
    WrongCat(const WrongCat &wrongcat);
    WrongCat &operator=(const WrongCat &wrongcat);
    void makeSound() const;
};
#endif // !WRONGCAT_HPP