#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form {
  private:
    std::string target;

  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &pre);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &robot);

    std::string getTarget() const;
    void printPardoned() const;

    virtual void execute(Bureaucrat const &executor) const;
};

#endif