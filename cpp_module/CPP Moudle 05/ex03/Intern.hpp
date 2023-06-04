#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
class Intern {
  private:
  public:
    Intern();
    ~Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    Form *makeForm(std::string form_name, std::string form_target);
};

#endif