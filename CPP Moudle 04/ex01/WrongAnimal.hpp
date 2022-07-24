#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
class WrongAnimal {
  protected:
    std::string type;

  public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal &wronganimal);
    WrongAnimal &operator=(const WrongAnimal &wronganimal);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif