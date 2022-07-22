#include "ClapTrap.hpp"

int main() {
    ClapTrap a("a");
    for (int i = 0; i < 5; i++)
        a.attack("b");
    for (int i = 0; i < 6; i++)
        a.takeDamage(1);
    a.attack("b");
    a.beRepaired(4);
}