#include <fstream>
#include <iostream>

void replacement(char **argv);

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "ARGC MUST BE FOUR" << std::endl;
        return 0;
    }
    replacement(argv);
}

void replacement(char **argv) {
    std::string tmp;
    std::string file_name = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream fin;
    fin.open(file_name);
    if (!fin.is_open()) {
        std::cout << "no such file" << std::endl;
        exit(0);
    }
    char c;
    while (true) {
        fin.get(c);
        if (fin.fail())
            break;
        tmp += c;
    }
    size_t index;
    if (tmp.find(s1) == std::string::npos) {
        std::cout << "no string such as " << s1 << std::endl;
        exit(0);
    }
    while (true) {
        index = tmp.find(s1);
        if (index == std::string::npos)
            break;
        tmp.erase(index, s1.length());
        tmp.insert(index, s2);
    }
    std::ofstream fout;
    fout.open(file_name + ".replace");
    fout << tmp;
    fin.close();
    fout.close();
}