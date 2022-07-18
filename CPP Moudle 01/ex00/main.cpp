#include "Zombie.hpp"

int main() {
    Zombie zombie;
    zombie.setName("zombie");
    zombie.announce();
    zombie.randomChump("random zombie");
    Zombie *newZombie;
    newZombie = zombie.newZombie("new zombie");
    delete (newZombie);
}