#include "easyfind.hpp"
#include <iostream>

int main(void) {

    std::vector<int> v;
    for (int i = -5; i < 5; i++)
        v.push_back(i);
    try {
        int index = easyfind(v, 2);
        std::cout << index << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}