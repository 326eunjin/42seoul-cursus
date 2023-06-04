#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>
class PhoneBook {
  private:
    int index;
    int size;
    Contact contact[8];
    bool is_right_form(std::string string);
    bool is_str_number(std::string string);
    std::string in_form(std::string string);
    void display_single(int index);
    void display_whole();

  public:
    PhoneBook();
    void search();
    void add();
};

#endif