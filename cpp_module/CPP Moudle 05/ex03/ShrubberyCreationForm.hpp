#ifndef SHUBBERY_CREATION_FORM_HPP
#define SHUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
  private:
    std::string target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &shurbbery);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shubbery);

    std::string getTarget() const;
    void writeASCII() const;

    virtual void execute(Bureaucrat const &executor) const;
};
#endif
