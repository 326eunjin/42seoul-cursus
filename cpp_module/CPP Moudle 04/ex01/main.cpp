#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    Cat c1;
    Cat c2;
    c1.getBrain()->setIdeaStr(0, "hi");
    c2 = c1;
    std::cout << c1.getBrain()->getIdeaStr(0) << std::endl;
    std::cout << c2.getBrain()->getIdeaStr(0) << std::endl;
    c2.getBrain()->setIdeaStr(0, "no hi");
    std::cout << c1.getBrain()->getIdeaStr(0) << std::endl;
    std::cout << c2.getBrain()->getIdeaStr(0) << std::endl;
    const Animal *(animal_array[5]);
    for (int i = 0; i < 3; i++)
        animal_array[i] = new Dog();
    for (int i = 3; i < 5; i++)
        animal_array[i] = new Cat();
    for (int i = 0; i < 5; i++)
        delete animal_array[i];
    system("leaks Animal");
}