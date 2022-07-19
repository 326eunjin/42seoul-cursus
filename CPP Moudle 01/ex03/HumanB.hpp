#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB {
  private:
    Weapon *weapon;
    std::string name;

  public:
    HumanB(std::string name);
    void setWeapon(Weapon &wepon);
    void attack();
};
#endif // !HUMANB_HPP