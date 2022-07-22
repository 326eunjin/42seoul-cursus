#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap Constructor initializes name is called" << std::endl;
    this->name = name;
    hit = 100;
    energy = 100;
    attack_damage = 30;
}

FragTrap::FragTrap() {
    std::cout << "FragTrap Constructor is called" << std::endl;
    name = "Annoymous";
    hit = 100;
    energy = 100;
    attack_damage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) {
    std::cout << "FragTrap Copy constructor is called" << std::endl;
    *this = fragtrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &fragtrap) {
        this->name = fragtrap.getName();
        this->hit = fragtrap.getHitPoints();
        this->energy = fragtrap.getEnergyPoints();
        this->attack_damage = fragtrap.getAttackDamage();
    }
    return (*this);
}

void FragTrap::highFivesGuys() {
    std::cout << "HIGH FIVES GUYS:>!" << std::endl;
}
