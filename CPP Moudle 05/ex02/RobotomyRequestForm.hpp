#ifndef ROBOT_TO_MY_REQUEST_FORM_HPP
#define ROBOT_TO_MY_REQUEST_FORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form {
  private:
    std::string target;

  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &robot);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &robot);

    std::string getTarget() const;
    void printRobotomized() const;

    virtual void execute(Bureaucrat const &executor) const;
};

#endif