#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name) { //참조자
    // this->name = name;
    this->weapon = &weapon; //포인터
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon->getType()
              << std::endl;
}