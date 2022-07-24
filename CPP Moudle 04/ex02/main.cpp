#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    // Animal a;
    Cat c1;
    Cat c2;
    c1.getBrain()->setIdeaStr(0, "hi");
    c2 = c1;
    std::cout << c1.getBrain()->getIdeaStr(0) << std::endl;
    std::cout << c2.getBrain()->getIdeaStr(0) << std::endl;
}