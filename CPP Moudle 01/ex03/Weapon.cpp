#include "Weapon.hpp"

void Weapon::setType(std::string type) { this->type = type; }

const std::string &Weapon::getType(void) {
    const std::string &ret = type;
    return (ret);
}

Weapon::Weapon(std::string type) { this->type = type; }

Weapon::Weapon() {}