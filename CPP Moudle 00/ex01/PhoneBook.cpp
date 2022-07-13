#include "PhoneBook.hpp"

int PhoneBook::is_right_form(std::string string) {
    for (int i = 0; i < (int)string.length(); i++) {
        if (std::isalpha(string[i]) == FALSE &&
            std::isspace(string[i]) == FALSE)
            return (FALSE);
    }
    return (TRUE);
}

int PhoneBook::is_str_number(std::string string) {
    for (int i = 0; i < (int)string.length(); i++) {
        if (std::isdigit(string[i]) == FALSE)
            return (FALSE);
    }
    return (TRUE);
}

PhoneBook::PhoneBook() { this->index = -1; }

void PhoneBook::display_single(int index) {
    if (index > 8 || index < 1)
        std::cout << "OUT OF RANGE " << std::endl;
    else {
        std::cout << "index is ";
        std::cout << ++index << std::endl;
        std::cout << "first name is ";
        std::cout << contact[index - 1].getFirstName() << std::endl;
        std::cout << "last name is ";
        std::cout << contact[index - 1].getLastName() << std::endl;
        std::cout << "nick name is ";
        std::cout << contact[index - 1].getNickName() << std::endl;
        std::cout << "phone number is ";
        std::cout << contact[index - 1].getPhoneNumber() << std::endl;
    }
}
void PhoneBook::search() {
    // display all
    for (int i = 0; i < 8; i++)
        display_single(i);
    // input index
    int index;
    std::cout << "INPUT INDEX" << std::endl;
    std::cin >> index;
    // print single one
    display_single(index);
}

void PhoneBook::add() {
    index++;
    size = index % 8;

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    while (1) {
        std::cout << "first name : ";
        std::cin >> first_name;
        if (is_right_form(first_name) == FALSE)
            break;
        std::cout << "invalid input" << std::endl;
    }
    while (1) {
        std::cout << "last name : ";
        std::cin >> last_name;
        if (is_right_form(last_name) == FALSE)
            break;
        std::cout << "invalid input" << std::endl;
    }
    std::cout << "nickname : ";
    std::cin >> nickname;
    while (1) {
        std::cout << "phone number : ";
        std::cin >> phone_number;
        if (is_str_number(phone_number) == FALSE)
            break;
        std::cout << "invalid input" << std::endl;
    }
    contact[size].setFirstName(first_name);
    contact[size].setLastName(last_name);
    contact[size].setNickName(nickname);
    contact[size].setPhoneNumber(phone_number);
}