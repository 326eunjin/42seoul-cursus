#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
class AAnimal {
  protected:
    std::string type;

  public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal &aanimal);
    AAnimal &operator=(const AAnimal &aanimal);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif