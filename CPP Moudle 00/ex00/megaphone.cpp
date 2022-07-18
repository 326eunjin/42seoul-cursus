#include <cctype>
#include <cstring>
#include <iostream>

void print_in_upper_case(std::string str);

int main(int argc, char **argv) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; i++)
            print_in_upper_case(argv[i]);
        std::cout << std::endl;
    }
}

void print_in_upper_case(std::string str) {
    std::string tmp;
    std::string const line(str);
    for (int i = 0; i < (int)str.length(); i++)
        tmp += std::toupper(line[i]);
    std::cout << tmp;
}