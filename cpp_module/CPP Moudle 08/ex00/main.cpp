#include "easyfind.hpp"
#include <iostream>

const char *NotInArray::what(void) const throw() { return "Not in array"; }
int main(void) {

    std::vector<int> v;
    for (float i = -5.0; i < 5; i++)
        v.push_back(i);
    try {
        int index = easyfind(v, 0);
        std::cout << index << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}