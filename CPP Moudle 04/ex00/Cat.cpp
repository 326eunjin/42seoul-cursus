#include "Cat.hpp"
#include <iostream>

// ANCHOR Cat canonical form
Cat::Cat() {
    std::cout << "Cat default constrcutor is called" << std::endl;
    type = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor is called" << std::endl; }

Cat::Cat(const Cat &cat) {
    std::cout << "Cat copy constructor is called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &cat) {
        this->type = cat.getType();
    }
    return (*this);
}

// ANCHOR Cat makeSound();
void Cat::makeSound() const { std::cout << "Cats meow" << std::endl; }