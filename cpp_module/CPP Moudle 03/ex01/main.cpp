#include "ScavTrap.hpp"

int main() {
    ScavTrap a("a");
    for (int i = 0; i < 5; i++)
        a.attack("b");
    for (int i = 0; i < 6; i++)
        a.takeDamage(1);
    a.attack("b");
    a.beRepaired(4);
    a.guardGate();
}