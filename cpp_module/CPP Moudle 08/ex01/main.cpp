#include "Span.hpp"
#include <iostream>
// int main() {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// } // 3 6 9 11 17

int main() {
    Span sp = Span(10000);
    for (int i = 0; i < 10000; i++)
        sp.addNumber(i);
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    // empty one or single element
    Span sp2 = Span(1);
    sp2.addNumber(1);
    try {
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    // more than initialized
    Span sp3 = Span(2);
    try {
        sp3.addNumber(0);
        sp3.addNumber(1);
        sp3.addNumber(2);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    // overloading
    std::vector<int> tmp;
    for (int i = 0; i < 5; i++)
        tmp.push_back(i);
    Span sp4 = Span(10);
    try {
        sp4.addNumber(tmp.begin(), tmp.end());
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    std::vector<int>::iterator it;
    for (it = sp4.getVector().begin(); it != sp4.getVector().end(); it++) {
        std::cout << "Sp4 element is " << *it << std::endl;
    }
}