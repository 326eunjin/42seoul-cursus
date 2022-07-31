#include <iostream>

struct Data {
    std::string s;
};

uintptr_t serialize(Data *ptr) {
    uintptr_t ret;
    ret = reinterpret_cast<uintptr_t>(ptr);
    return (ret);
}

Data *deserialize(uintptr_t raw) {
    Data *d;
    d = reinterpret_cast<Data *>(raw);
    return (d);
}

int main() {
    Data d;
    d.s = "abc";
    uintptr_t u = serialize(&d);
    std::cout << &d << std::endl;
    std::cout << std::hex << u << std::endl;

    Data *ptr = deserialize(u);
    std::cout << ptr->s << std::endl;
}