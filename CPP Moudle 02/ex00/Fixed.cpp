#include "Fixed.hpp"
#include <iostream>

const int Fixed::bits_num = 8;

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

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
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point = fixed.getRawBits();
    return (*this);
}