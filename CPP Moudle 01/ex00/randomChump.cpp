#include "Zombie.hpp"

void Zombie::randomChump(std::string name) {
    Zombie *zombie = new Zombie();
    zombie->name = name;
    zombie->announce();
    delete (zombie);
}