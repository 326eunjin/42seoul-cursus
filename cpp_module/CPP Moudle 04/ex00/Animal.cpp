#include "Animal.hpp"
#include <iostream>

// ANCHOR Animal Canonical Form
Animal::Animal() {
    std::cout << "Animal default constrcutor is called" << std::endl;
    type = "animal";
}

Animal::~Animal() { std::cout << "Animal destructor is called" << std::endl; }

Animal::Animal(const Animal &animal) {
    std::cout << "Animal copy constructor is called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &animal) {
        this->type = animal.getType();
    }
    return (*this);
}

// ANCHOR Animal getter makeSound();
std::string Animal::getType() const { return type; }

void Animal::makeSound() const {
    std::cout << "Animal make sound" << std::endl;
}
