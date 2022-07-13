#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook
{
private:
  int index;
  int size;
  Contact contact[8];
  bool is_right_form(std::string string);
  bool is_str_number(std::string string);

public:
  PhoneBook();
  void display_single(int index);
  void search();
  void add();
  int is_right_form();
};

#endif