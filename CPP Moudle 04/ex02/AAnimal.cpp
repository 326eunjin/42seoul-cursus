#include "AAnimal.hpp"
#include <iostream>

// ANCHOR AAnimal Canonical Form
AAnimal::AAnimal() {
    std::cout << "AAnimal default constrcutor is called" << std::endl;
    type = "aanimal";
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aanimal) {
    std::cout << "AAnimal copy constructor is called" << std::endl;
    *this = aanimal;
}

AAnimal &AAnimal::operator=(const AAnimal &aanimal) {
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &aanimal) {
        this->type = aanimal.getType();
    }
    return (*this);
}

// ANCHOR AAnimal getter makeSound();
std::string AAnimal::getType() const { return type; }

void AAnimal::makeSound() const {
    std::cout << "AAnimal make sound" << std::endl;
}
