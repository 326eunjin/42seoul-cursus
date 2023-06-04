#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
template <typename T>
void iter(T *array, int len, void (*ptr)(T const &element)) {
    for (int i = 0; i < len; i++)
        ptr(array[i]);
}

template <typename T> void ptr(T const &element) {
    std::cout << element << std::endl;
}
#endif
