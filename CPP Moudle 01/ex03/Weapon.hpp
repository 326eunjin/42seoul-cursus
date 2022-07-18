#ifndef WEAPON_H
#define WEAPON_H

#include <string>
class Weapon {
  private:
    std::string type;

  public:
    const std::string &getType();
    void setType(std::string type);
    Weapon(std::string str);
    Weapon();
};

#endif