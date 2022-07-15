#include "PhoneBook.hpp"

bool PhoneBook::is_right_form(std::string string) {
    if (string.empty())
        return false;
    for (int i = 0; i < (int)string.length(); i++) {
        if (std::isalpha(string[i]) == 0 && std::isspace(string[i]) == 0)
            return false;
    }
    return true;
}

bool PhoneBook::is_str_number(std::string string) {
    if (string.empty())
        return false;
    for (int i = 0; i < (int)string.length(); i++) {
        if (std::isdigit(string[i]) == 0)
            return false;
    }
    return true;
}

void PhoneBook::without_whitespace(std::string &string) {
    string.erase(std::remove_if(string.begin(), string.end(), ::isspace),
                 string.end());
}

PhoneBook::PhoneBook() { this->index = -1; }

std::string PhoneBook::in_form(std::string string) {
    string.append("|");
    if (string.length() > 11) {
        string.at(9) = '.';
        string.erase(10);
        string.append("|");
    }
    return (string);
}
void PhoneBook::display_single(int index) {
    // std::cout << std::right << std::setw(11) << " |     INDEX|" << std::endl;
    std::cout << std::right << std::setw(11) << "|         " << index << "|"
              << std::right << std::setw(11)
              << in_form(contact[index - 1].getFirstName()) << std::right
              << std::setw(11) << in_form(contact[index - 1].getLastName())
              << std::right << std::setw(11)
              << in_form(contact[index - 1].getNickName()) << std::endl;
}
void PhoneBook::search() {
    for (int i = 0; i < 8; i++)
        display_single(i + 1);
    int index;
    std::cout << "INPUT INDEX(1~8) >> ";
    std::cin >> index;
    while (std::cin.fail() || index < 1 || index > 8) {
        if (std::cin.eof() == true)
            exit(0);
        std::cin.clear();
        std::cin.ignore(256, '\n'); //입력버퍼 비우기
        std::cout << "INVALID INPUT" << std::endl;
        std::cout << "INPUT INDEX(1~8) >> ";
        std::cin >> index;
    }
    std::cin.clear();
    std::cin.ignore(256, '\n'); //입력버퍼 비우기
    display_single(index);
}

void PhoneBook::add() {
    index++;
    size = index % 8;

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::cout << "first name : ";
    while (true) {
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            exit(0);
        if (is_right_form(first_name) == true) {
            without_whitespace(first_name);
            break;
        }
        std::cout << "invalid input" << std::endl;
        std::cout << "first name : ";
    }
    std::cout << "last name : ";
    while (true) {

        std::getline(std::cin, last_name);
        if (std::cin.eof() == true)
            exit(0);
        if (is_right_form(last_name) == true) {
            without_whitespace(last_name);
            break;
        }
        std::cout << "invalid input" << std::endl;
        std::cout << "last name : ";
    }
    std::cout << "nickname : ";
    while (true) {
        std::getline(std::cin, nickname);
        if (std::cin.eof() == true)
            exit(0);
        if (nickname.empty() == false) {
            without_whitespace(nickname);
            break;
        }
        std::cout << "invalid input" << std::endl;
        std::cout << "nickname : ";
    }
    std::cout << "phone number : ";
    while (true) {
        std::getline(std::cin, phone_number);
        if (std::cin.eof() == true)
            exit(0);
        if (is_str_number(phone_number) == true) {
            without_whitespace(phone_number);
            break;
        }
        std::cout << "invalid input" << std::endl;
        std::cout << "phone number : ";
    }
    contact[size].setFirstName(first_name);
    contact[size].setLastName(last_name);
    contact[size].setNickName(nickname);
    contact[size].setPhoneNumber(phone_number);
}