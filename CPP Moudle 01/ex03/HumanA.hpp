#include "Weapon.hpp"
#include <string>
class HumanA {
  private:
    Weapon *weapon;
    std::string name;

  public:
    HumanA(std::string name, Weapon &weapon);
    void attack();
};
