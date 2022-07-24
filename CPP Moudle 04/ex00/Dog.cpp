#include "Dog.hpp"
#include <iostream>

// ANCHOR Dog canonical form
Dog::Dog() {
    std::cout << "Dog default constrcutor is called" << std::endl;
    type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor is called" << std::endl; }

Dog::Dog(std::string name) {
    std::cout << "Dog constrcutor that initialized type is called" << std::endl;
    type = name;
}

Dog::Dog(const Dog &dog) {
    std::cout << "Dog copy constructor is called" << std::endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &dog) {
        this->type = dog.getType();
    }
    return (*this);
}

// ANCHOR Dog makeSound();
void Dog::makeSound() const { std::cout << "Dogs bark" << std::endl; }