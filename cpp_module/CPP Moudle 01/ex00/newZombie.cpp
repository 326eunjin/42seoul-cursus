#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name) {
    Zombie *newZombie = new Zombie();
    newZombie->name = name;
    newZombie->announce();
    return (newZombie);
} // you should delete outside class