#include "WrongCat.hpp"
#include <iostream>

// ANCHOR WrongCat canonical form
WrongCat::WrongCat() {
    std::cout << "WrongCat default constrcutor is called" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat::WrongCat(std::string name) {
    std::cout << "WrongCat constrcutor that initialized type is called"
              << std::endl;
    type = name;
}

WrongCat::WrongCat(const WrongCat &wrongcat) {
    std::cout << "WrongCat copy constructor is called" << std::endl;
    *this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &wrongcat) {
        this->type = wrongcat.getType();
    }
    return (*this);
}

// ANCHOR WrongCat makeSound();
void WrongCat::makeSound() const { std::cout << "WrongCats meow" << std::endl; }