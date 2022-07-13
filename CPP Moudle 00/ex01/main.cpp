#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook phonebook;
    Contact contact;
    std::string command;
    std::cout << "PLEASE INSERT SEARCH/ADD/EXIT" << std::endl;
    std::cout << "ANY OTHER INPUT IS INVALID" << std::endl;
    while (getline(std::cin, command))
    {
        if (std::cin.eof())
            exit(0);
        if (command.compare("ADD") == 0)
            phonebook.add();
        else if (command.compare("SEARCH") == 0)
            phonebook.search();
        else if (command.compare("EXIT") == 0)
            exit(0);
        else
            std::cout << "INVALID INPUT!!!!" << std::endl;
        std::cout << "PLEASE INSERT SEARCH/ADD/EXIT" << std::endl;
        std::cout << "ANY OTHER INPUT IS INVALID" << std::endl;
    }
}
