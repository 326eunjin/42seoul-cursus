#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
    Intern intern;
    Form *shu = intern.makeForm("shrubbery", "i1");
    Form *robo = intern.makeForm("robotomy", "2");
    Form *inter = intern.makeForm("presidentialpardon", "3");
    delete shu;
    delete robo;
    delete inter;
    intern.makeForm("no", "not exist");
    system("leaks Intern");
}