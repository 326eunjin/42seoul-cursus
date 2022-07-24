#include "Cat.hpp"
#include <iostream>

// ANCHOR Cat canonical form
Cat::Cat() {
    std::cout << "Cat default constrcutor is called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor is called" << std::endl;
}

Cat::Cat(std::string name) {
    std::cout << "Cat constrcutor that initialized type is called" << std::endl;
    type = name;
    brain = new Brain();
}

Cat::Cat(const Cat &cat) {
    std::cout << "Cat copy constructor is called" << std::endl;
    this->brain = new Brain();
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &cat) {
        this->type = cat.getType();
        for (int i = 0; i < 100; i++) //하나하나 넘겨줌
            this->brain->setIdeaStr(i, cat.getBrain()->getIdeaStr(i));
    }
    return (*this);
}

// ANCHOR Cat makeSound(); getBrain();
void Cat::makeSound() const { std::cout << "Cats meow" << std::endl; }

Brain *Cat::getBrain() const { return (brain); }