#include "iter.hpp"
#include <iostream>

int main() {
    int a[5] = {0, 1, 2, 3, 4};
    iter(a, 5, ptr);

    double b[2] = {12.23, 23.34};
    iter(b, 2, ptr);
}