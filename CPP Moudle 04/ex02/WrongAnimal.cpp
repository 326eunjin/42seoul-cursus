#include "WrongAnimal.hpp"
#include <iostream>

// ANCHOR WrongAnimal Canonical Form
WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constrcutor is called" << std::endl;
    type = "wrong animal";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
    std::cout << "WrongAnimal copy constructor is called" << std::endl;
    *this = animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &animal) {
        this->type = animal.getType();
    }
    return (*this);
}

// ANCHOR WrongAnimal makeSound();
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal make sound" << std::endl;
}
std::string WrongAnimal::getType() const { return type; }
