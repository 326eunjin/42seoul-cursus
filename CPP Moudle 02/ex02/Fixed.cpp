#include "Fixed.hpp"

const int Fixed::bits_num = 8;

int Fixed::getRawBits(void) const { return fixed_point; }

void Fixed::setRawBits(int const raw) { this->fixed_point = raw; }

Fixed::Fixed() { fixed_point = 0; }

Fixed::Fixed(const Fixed &fixed_new) { *this = fixed_new; }

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed &fixed) {
    if (this->fixed_point > fixed.fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &fixed) {
    if (this->fixed_point == fixed.fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &fixed) {
    if (this->fixed_point != fixed.fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &fixed) {
    if (this->fixed_point >= fixed.fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &fixed) {
    if (this->fixed_point <= fixed.fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &fixed) {
    if (this->fixed_point < fixed.fixed_point)
        return (true);
    return (false);
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    this->fixed_point = fixed.fixed_point;
    return (*this);
}

Fixed Fixed::operator+(const Fixed &fixed) {
    Fixed ret;
    ret.fixed_point = this->fixed_point + fixed.fixed_point;
    return (ret);
}

Fixed Fixed::operator-(const Fixed &fixed) {
    Fixed ret;
    ret.fixed_point = this->fixed_point - fixed.fixed_point;
    return (ret);
}

Fixed Fixed::operator*(const Fixed &fixed) {
    Fixed ret(this->toFloat() * fixed.toFloat());
    return (ret);
}

Fixed Fixed::operator/(const Fixed &fixed) {
    Fixed ret(this->toFloat() / fixed.toFloat());
    return (ret);
}

Fixed &Fixed::operator++() {
    fixed_point += 1;
    return (*this);
}

Fixed &Fixed::operator--() {
    fixed_point += 1;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    fixed_point += 1;
    return (temp);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    fixed_point -= 1;
    return (temp);
}

Fixed::Fixed(const int i) { fixed_point = i << bits_num; }

Fixed::Fixed(float i) { fixed_point = roundf(i * (1 << bits_num)); }

int Fixed::toInt() const {
    int ret = fixed_point >> bits_num;
    return (ret);
}

float Fixed::toFloat() const {
    float ret;
    ret = float(fixed_point) / (1 << bits_num);
    return (ret);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed &Fixed::min(Fixed &fixed_1, Fixed &fixed_2) {
    if (fixed_1.fixed_point < fixed_2.fixed_point)
        return (fixed_1);
    return (fixed_2);
}

Fixed &Fixed::max(Fixed &fixed_1, Fixed &fixed_2) {
    if (fixed_1.fixed_point < fixed_2.fixed_point)
        return (fixed_2);
    return (fixed_1);
}

const Fixed &Fixed::min(const Fixed &fixed_1, const Fixed &fixed_2) {
    if (fixed_1.fixed_point < fixed_2.fixed_point)
        return (fixed_1);
    return (fixed_2);
}

const Fixed &Fixed::max(const Fixed &fixed_1, const Fixed &fixed_2) {
    if (fixed_1.fixed_point < fixed_2.fixed_point)
        return (fixed_2);
    return (fixed_1);
}