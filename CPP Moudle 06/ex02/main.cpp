#include "Base.hpp"

int main() {
    srand(time(NULL));
    Base *ptr;
    ptr = generate();
    identify(ptr);
}