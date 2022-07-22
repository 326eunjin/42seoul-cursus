#include "ClapTrap.hpp"
#include <iostream>

// ANCHOR Canonical Form
ClapTrap::ClapTrap(std::string name) {
    std::cout << "Constructor initializes name is called" << std::endl;
    this->name = name;
    hit = 10;
    energy = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap() {
    std::cout << "Constructor is called" << std::endl;
    name = "Annoymous";
    hit = 10;
    energy = 10;
    attack_damage = 0;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor is called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
    std::cout << "Copy constructor is called" << std::endl;
    *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &claptrap) {
        this->name = claptrap.getName();
        this->hit = claptrap.getHitPoints();
        this->energy = claptrap.getEnergyPoints();
        this->attack_damage = claptrap.getAttackDamage();
    }
    return (*this);
}

// ANCHOR member function
void ClapTrap::attack(const std::string &target) {
    if (energy <= 0 || hit <= 0) {
        std::cout << "No energy or hit point is left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage!";
    energy--;
    std::cout << " [hit point : " << hit << "]";
    std::cout << " [energy : " << energy << "]" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (energy <= 0 || hit <= 0) {
        std::cout << "No energy or hit point is left" << std::endl;
        return;
    } else if (amount >= hit) {
        std::cout << "DIED" << std::endl;
        return;
    }
    hit -= amount;
    std::cout << "ClapTrap " << name << " took " << amount
              << " points of damage";
    std::cout << " [hit point : " << hit << "]";
    std::cout << " [energy : " << energy << "]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy <= 0 || hit <= 0) {
        std::cout << "No energy or hit point is left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " took " << amount
              << " points of repaired";
    hit += amount;
    energy--;
    std::cout << " [hit point : " << hit << "]";
    std::cout << " [energy : " << energy << "]" << std::endl;
}

// ANCHOR getter
std::string ClapTrap::getName() const { return name; }

unsigned int ClapTrap::getHitPoints() const { return hit; }

unsigned int ClapTrap::getEnergyPoints() const { return energy; }

unsigned int ClapTrap::getAttackDamage() const { return attack_damage; }
