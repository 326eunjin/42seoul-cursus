#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap Constructor initializes name is called" << std::endl;
    this->name = name;
    hit = 100;
    energy = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Constructor is called" << std::endl;
    name = "Annoymous";
    hit = 100;
    energy = 50;
    attack_damage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Scavtrap) {
    std::cout << "ScavTrap Copy constructor is called" << std::endl;
    *this = Scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &Scavtrap) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &Scavtrap) {
        this->name = Scavtrap.getName();
        this->hit = Scavtrap.getHitPoints();
        this->energy = Scavtrap.getEnergyPoints();
        this->attack_damage = Scavtrap.getAttackDamage();
    }
    return (*this);
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energy <= 0 || hit <= 0) {
        std::cout << "ScavTrap -> No energy or hit point is left" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!";
    energy--;
    std::cout << " [hit point : " << hit << "]";
    std::cout << " [energy : " << energy << "]" << std::endl;
}
