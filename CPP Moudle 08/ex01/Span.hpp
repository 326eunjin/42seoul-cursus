#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span {
  private:
    std::vector<int> v;
    unsigned int n;

  public:
    Span();
    Span(unsigned int n);
    ~Span();
    Span(const Span &s);
    Span &operator=(const Span &s);

    unsigned int getN() const;
    std::vector<int> getVector() const;
    void addNumber(int add);
    int shortestSpan();
    int longestSpan();

    class NotEnoughElement : public std::exception {
      public:
        const char *what() const throw();
    };

    class FullVector : public std::exception {
      public:
        const char *what() const throw();
    };
};

#endif // !SPAN_HPP