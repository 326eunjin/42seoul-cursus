#include "Conversion.hpp"

int main(int argc, char **argv) {
    std::cout << std::fixed << std::setprecision(1);
    Conversion c;
    if (argc != 2) {
        std::cout << "Argc must be two" << std::endl;
        return 0;
    }
    c.printType(argv[1]);
    return 0;
}