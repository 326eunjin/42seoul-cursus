#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "ARGC MUST BE TWO" << std::endl;
        exit(0);
    }
    Harl harl;
    std::string str = argv[1];
    harl.complain(str);
}