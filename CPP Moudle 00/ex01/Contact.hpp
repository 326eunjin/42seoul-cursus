#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

  public:
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickName(std::string nickname);
    void setPhoneNumber(std::string phone_number);
    void setDarkestSecret(std::string darkest_secret);
};

#endif