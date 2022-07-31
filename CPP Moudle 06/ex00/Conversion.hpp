#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>

enum Types { CHAR, INT, DOUBLE, FLOAT, ERROR };
class Conversion {
  private:
    std::string input;
    Types type;

  public:
    Conversion();
    ~Conversion();
    Conversion(const Conversion &conv);
    Conversion &operator=(const Conversion &conv);

    std::string getInput() const;
    Types getType() const;

    void fromChar(char c);
    void fromInt(int i);
    void fromFloat(float f);
    void fromDouble(double d);

    void printType(char *str);
};
#endif