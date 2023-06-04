#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
class WrongAnimal {
  protected:
    std::string type;

  public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal &wronganimal);
    WrongAnimal &operator=(const WrongAnimal &wronganimal);

    std::string getType() const;
    void makeSound() const;
};

#endif