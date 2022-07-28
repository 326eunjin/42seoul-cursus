#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
// ANCHOR canonical form
RobotomyRequestForm::RobotomyRequestForm() : Form("Default Roboto", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("Default Roboto", 72, 45) {
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robot)
    : Form("Default Roboto", robot.getSignGrade(), robot.getExecuteGrade()) {
    *this = robot;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &robot) {
    if (this != &robot)
        this->target = robot.getTarget();
    return (*this);
}

// ANCHOR getter
std::string RobotomyRequestForm::getTarget() const { return target; }

// ANCHOR random
void RobotomyRequestForm::printRobotomized() const {
    srand(time(NULL));
    int a = rand() % 2;
    if (a == 0)
        std::cout << target << " has been robotized" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (getSign() == false)
        throw Form::NotSigned();
    if (getExecuteGrade() < executor.getGrade())
        throw Form::GradeTooLowException();
    printRobotomized();
}