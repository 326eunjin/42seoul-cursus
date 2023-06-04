#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
    Base *ptr;
    int num = rand() % 3;
    if (num == 0) {
        std::cout << "Generate new A class" << std::endl;
        ptr = new A();
    } else if (num == 1) {
        std::cout << "Generate new B class" << std::endl;
        ptr = new B();
    } else {
        std::cout << "Generate new C class" << std::endl;
        ptr = new C();
    }
    return ptr;
}

void identify(Base *p) {
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);
    if (a)
        std::cout << "identify A by using pointer" << std::endl;
    else if (b)
        std::cout << "identify B by using pointer" << std::endl;
    else if (c)
        std::cout << "identify C by using pointer" << std::endl;
    return;
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        static_cast<void>(a);
        std::cout << "identify A" << std::endl;
        return;
    } catch (const std::exception &e) {
    }
    try {
        B &b = dynamic_cast<B &>(p);
        static_cast<void>(b);
        std::cout << "identify B" << std::endl;
        return;
    } catch (const std::exception &e) {
    }
    try {
        C &c = dynamic_cast<C &>(p);
        static_cast<void>(c);
        std::cout << "identify C" << std::endl;
        return;
    } catch (const std::exception &e) {
    }
    return;
}
int main() {
    srand(time(NULL));
    Base *ptr;
    ptr = generate();
    identify(ptr);
    identify(*ptr);
}