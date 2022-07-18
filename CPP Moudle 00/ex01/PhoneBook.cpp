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

PhoneBook::PhoneBook() { this->index = -1; }

std::string PhoneBook::in_form(std::string string) {
    std::string ret;
    ret = string;
    if (ret.length() > 11) {
        ret.at(9) = '.'; // 9번째 문자를 .로 바꿈
        ret = ret.substr(0, 10);
    }
    ret.append("|");
    return (ret);
}

void PhoneBook::display_whole() {
    std::cout << std::setw(11) << "INDEX|" << std::right << std::setw(11)
              << "FIRST NAME|" << std::right << std::setw(11) << "LAST NAME|"
              << std::right << std::setw(11) << "NICK NAME|" << std::endl;
    for (int i = 1; i <= 8; i++) {
        std::cout << std::right << std::setw(10) << i << "|" << std::right
                  << std::setw(11) << in_form(contact[i - 1].getFirstName())
                  << std::right << std::setw(11)
                  << in_form(contact[i - 1].getLastName()) << std::right
                  << std::setw(11) << in_form(contact[i - 1].getNickName())
                  << std::endl;
    }
}
void PhoneBook::display_single(int index) {
    std::cout << "------------------------------------------------------"
              << std::endl;
    std::cout << "First name is " << contact[index - 1].getFirstName()
              << std::endl;
    std::cout << "Last name is " << contact[index - 1].getLastName()
              << std::endl;
    std::cout << "Nickname is " << contact[index - 1].getNickName()
              << std::endl;
    std::cout << "Phone number is " << contact[index - 1].getPhoneNumber()
              << std::endl;
    std::cout << "Darkest secret is " << contact[index - 1].getDarkestSecret()
              << std::endl;
    std::cout << "------------------------------------------------------"
              << std::endl;
}

void PhoneBook::search() {
    display_whole();
    char index;
    std::cout << "INPUT INDEX(1~8) >> ";
    index = std::cin.get();
    while (std::cin.fail() || index < '1' || index > '8') {
        if (std::cin.eof() == true)
            exit(0);
        std::cin.clear();
        std::cin.ignore(LLONG_MAX, '\n');
        //입력버퍼 비우기 /최대 문자 수를 버림. 단,
        //그전에 뉴라인 문자를 버리면 곧바로 멈춤
        //(실질적으로 한 줄을 모두 버리는 코드)
        std::cout << "INVALID INPUT" << std::endl;
        std::cout << "INPUT INDEX(1~8) >> ";
        index = std::cin.get();
    }
    std::cin.clear();
    std::cin.ignore(LLONG_MAX, '\n'); //입력버퍼 비우기
    display_single(index - 48);
}

void PhoneBook::add() {
    index++;
    size = index % 8;

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    std::cout << "first name : ";
    while (true) {
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            exit(0);
        if (is_right_form(first_name) == true)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "first name : ";
    }
    std::cout << "last name : ";
    while (true) {

        std::getline(std::cin, last_name);
        if (std::cin.eof() == true)
            exit(0);
        if (is_right_form(last_name) == true)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "last name : ";
    }
    std::cout << "nickname : ";
    while (true) {
        std::getline(std::cin, nickname);
        if (std::cin.eof() == true)
            exit(0);
        if (nickname.empty() == false)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "nickname : ";
    }
    std::cout << "phone number : ";
    while (true) {
        std::getline(std::cin, phone_number);
        if (std::cin.eof() == true)
            exit(0);
        if (is_str_number(phone_number) == true)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "phone number : ";
    }
    std::cout << "darkest secret : ";
    while (true) {
        std::getline(std::cin, darkest_secret);
        if (std::cin.eof() == true)
            exit(0);
        if (nickname.empty() == false)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "darkest secret : ";
    }
    contact[size].setFirstName(first_name);
    contact[size].setLastName(last_name);
    contact[size].setNickName(nickname);
    contact[size].setPhoneNumber(phone_number);
    contact[size].setDarkestSecret(darkest_secret);
}