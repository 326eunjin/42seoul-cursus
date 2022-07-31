#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base::~Base() { std::cout << "Base" << std::endl; }
Base *generate(void) {
    Base *ptr;
    int num = rand() % 3;
    if (num == 0)
        ptr = new A();
    else if (num == 1)
        ptr = new B();
    else
        ptr = new C();
    return ptr;
}

void identify(Base *p) {
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);
}

void identiy(Base &p) {
    A &a = dynamic_cast<A &>(p);
    B &b = dynamic_cast<B &>(p);
    C &c = dynamic_cast<C &>(p);
}