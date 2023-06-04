#include "ClapTrap.hpp"

int main() {
    ClapTrap a("a");
    for (int i = 0; i < 10; i++)
        a.attack("b");
    a.beRepaired(4);
    for (int i = 0; i < 8; i++)
        a.takeDamage(1);
    a.attack("b");
    a.beRepaired(4);
}