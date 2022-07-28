#include "Bureaucrat.hpp"
#include <iostream>
int main() {
    // constructor try catch
    try {
        for (int i = 149; i < 152; i++)
            Bureaucrat a("meme", i);

    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        for (int i = 2; i > -1; i--)
            Bureaucrat a("nini", i);

    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    // increment
    try {
        Bureaucrat a("meme", 150);
        a.decrementGrade();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        Bureaucrat b("meme", 1);
        b.incrementGrade();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat c("b", 2);
    std::cout << c;
}