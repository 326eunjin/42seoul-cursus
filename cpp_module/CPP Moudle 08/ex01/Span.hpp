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
    template <typename T> void addNumber(T begin, T end);
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

template <typename T> void Span::addNumber(T begin, T end) {
    if (std::distance(begin, end) + Span::v.size() > n)
        throw Span::FullVector();
    for (T t = begin; t != end; t++)
        Span::v.push_back(*t);
}
#endif // !SPAN_HPP