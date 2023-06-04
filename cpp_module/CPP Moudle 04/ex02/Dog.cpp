#include "Dog.hpp"
#include <iostream>

// ANCHOR Dog canonical form
Dog::Dog() {
    std::cout << "Dog default constrcutor is called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog(const Dog &dog) {
    std::cout << "Dog copy constructor is called" << std::endl;
    this->brain = new Brain();
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &dog) {
        this->type = dog.getType();
        for (int i = 0; i < 100; i++)
            this->brain->setIdeaStr(i, dog.getBrain()->getIdeaStr(i));
    }
    return (*this);
}

// ANCHOR Dog makeSound();getBrain();
void Dog::makeSound() const { std::cout << "Dogs bark" << std::endl; }

Brain *Dog::getBrain() const { return (brain); }