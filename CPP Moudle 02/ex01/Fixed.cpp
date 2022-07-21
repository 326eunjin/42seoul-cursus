#include "Fixed.hpp"

const int Fixed::bits_num = 8;

int Fixed::getRawBits(void) const { return fixed_point; }

void Fixed::setRawBits(int const raw) { this->fixed_point = raw; }

Fixed::Fixed() {
    fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_new) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed_new; //세번째 줄!
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
    //*this = fixed;
    this->fixed_point = fixed.fixed_point;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::Fixed(const int i) {
    fixed_point = i << bits_num;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float i) {
    fixed_point = roundf(i * (1 << bits_num));
    std::cout << "Float constructor called" << std::endl;
}

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
