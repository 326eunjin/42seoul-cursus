#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
  private:
    int fixed_point;
    static const int bits_num;

  public:
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed();
    Fixed(const int i);
    Fixed(const float i);
    int toInt(void) const;
    float toFloat(void) const;
    ~Fixed();
    Fixed(const Fixed &fixed_new);
    Fixed &operator=(const Fixed &fixed); //할당 연산자 오버로딩

    Fixed operator+(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed);
    Fixed operator*(const Fixed &fixed);
    Fixed operator/(const Fixed &fixed);

    bool operator>(const Fixed &fixed);
    bool operator>=(const Fixed &fixed);
    bool operator<(const Fixed &fixed);
    bool operator<=(const Fixed &fixed);
    bool operator==(const Fixed &fixed);
    bool operator!=(const Fixed &fixed);

    Fixed &operator++();   //전위
    Fixed operator++(int); //후위
    Fixed &operator--();   //전위
    Fixed operator--(int); //후위

    static Fixed &min(Fixed &fixed_1, Fixed &fixed_2);
    static const Fixed &min(const Fixed &fixed_1, const Fixed &fixed_2);
    static Fixed &max(Fixed &fixed_1, Fixed &fixed_2);
    static const Fixed &max(const Fixed &fixed_1, const Fixed &fixed_2);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif