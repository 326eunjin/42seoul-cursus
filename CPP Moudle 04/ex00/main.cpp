#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *z = new WrongAnimal();
    const WrongAnimal *z2 = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << z->getType() << " " << std::endl;
    std::cout << z2->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    z->makeSound();
    z2->makeSound();
    delete meta;
    delete j;
    delete i;
    delete z;
    delete z2;
    system("leaks Animal");
}