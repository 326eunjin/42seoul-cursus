#include "PhoneBook.hpp"

bool PhoneBook::is_right_form(std::string string)
{
    if (string.empty())
        return false;
    for (int i = 0; i < (int)string.length(); i++)
    {
        if (std::isalpha(string[i]) == 0 &&
            std::isspace(string[i]) == 0)
            return false;
    }
    return true;
}

bool PhoneBook::is_str_number(std::string string)
{
    if (string.empty())
        return false;
    for (int i = 0; i < (int)string.length(); i++)
    {
        if (std::isdigit(string[i]) == 0)
            return false;
    }
    return true;
}

PhoneBook::PhoneBook() { this->index = -1; }

void PhoneBook::display_single(int index)
{
    if (index > 8 || index < 0)
        std::cout << "OUT OF RANGE " << std::endl;
    else
    {
        std::cout << "index is ";
        std::cout << index << std::endl;
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
void PhoneBook::search()
{
    // display all
    for (int i = 0; i < 8; i++)
        display_single(i + 1);
    // input index
    int index;
    std::cout << "INPUT INDEX(1~8)";
    std::cin >> index;
    // print single one
    display_single(index);
}

void PhoneBook::add()
{
    index++;
    size = index % 8;

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::cout << "first name : ";
    while (getline(std::cin, first_name))
    {
        if (std::cin.eof())
            exit(0);
        if (is_right_form(first_name) == true)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "first name : ";
    }
    std::cout << "last name : ";
    while (getline(std::cin, last_name))
    {

        if (std::cin.eof())
            exit(0);
        if (is_right_form(last_name) == true)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "last name : ";
    }
    while (getline(std::cin, nickname))
    {
        if (nickname.empty() == false)
            break;
        std::cout << "invalid input" << std::endl;
    }
    // std::cout << "nickname : ";
    // std::cin >> nickname;
    // if (nickname.empty())
    //     return false;
    std::cout << "phone number : ";
    while (getline(std::cin, phone_number))
    {
        if (std::cin.eof())
            exit(0);
        if (is_str_number(phone_number) == true)
            break;
        std::cout << "invalid input" << std::endl;
        std::cout << "phone number : ";
    }
    contact[size].setFirstName(first_name);
    contact[size].setLastName(last_name);
    contact[size].setNickName(nickname);
    contact[size].setPhoneNumber(phone_number);
}