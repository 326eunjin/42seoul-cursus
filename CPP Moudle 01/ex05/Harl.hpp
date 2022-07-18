#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl {
  private:
    void debug();
    void info();
    void warning();
    void error();

  public:
    void complain(std::string level);
};

#endif