#include "Span.hpp"

// ANCHOR canonical form
Span::Span() { n = 0; }

Span::Span(unsigned int n) { this->n = n; }

Span::~Span() {}

Span::Span(const Span &span) { *this = span; }

Span &Span::operator=(const Span &span) {
    if (this != &span) {
        this->n = span.getN();
        this->v = span.getVector();
    }
    return (*this);
}

// ANCHOR getter
unsigned int Span::getN() const { return n; }

std::vector<int> Span::getVector() const { return v; }

// ANCHOR addNumber();
void Span::addNumber(int add) {
    if (v.size() >= n) {
        throw FullVector();
    }
    v.push_back(add);
}

// ANCHOR longest
int Span::longestSpan() {
    if (v.size() == 1 || v.empty() == true)
        throw NotEnoughElement();
    int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());
    return (max - min);
}

// ANCHOR shortest
int Span::shortestSpan() {
    if (v.size() == 1 || v.empty() == true)
        throw NotEnoughElement();
    //정렬
    std::sort(v.begin(), v.end());
    //포문돌면서 자기꺼랑 자기 뒤에꺼랑 차이 비교하기
    int ret = longestSpan();
    for (int i = 0; i < (int)v.size() - 1; i++) {
        int tmp = v.at(i + 1) - v.at(i);
        if (ret > tmp)
            ret = tmp;
    }
    return (ret);
}

// ANCHOR exception
const char *Span::FullVector::what(void) const throw() {
    return "Vector is now full.";
}

const char *Span::NotEnoughElement::what(void) const throw() {
    return "Vector is empty or has only one element";
}