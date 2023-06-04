#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    // constructor try catch
    try {
        for (int i = 149; i < 152; i++)
            Form a("meme", i, i);

    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        for (int i = 2; i > -1; i--)
            Form a("nini", i, i);

    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    Bureaucrat b("b", 100);
    Form a("special form", 97, 97);
    for (int i = 0; i < 3; i++) {
        b.incrementGrade();
        b.signForm(a);
    }
}