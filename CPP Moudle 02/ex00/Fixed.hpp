#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
  private:
    int fixed_point;
    static const int bits_num;

  public:
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed_new);
    Fixed &operator=(const Fixed &fixed); //할당 연산자 오버로딩
};

#endif