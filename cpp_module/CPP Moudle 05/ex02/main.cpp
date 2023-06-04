#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
    std::srand(std::time(NULL));
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 10);
    Bureaucrat b3("b3", 60);
    Bureaucrat b4("b4", 140);
    Bureaucrat b5("b5", 150);

    std::cout << "Shrubbery Test" << std::endl;
    ShrubberyCreationForm s("shub");
    b1.signForm(s); // sign
    b2.signForm(s); // sign
    b3.signForm(s); // sign
    b4.signForm(s); // sign
    b5.signForm(s); // no sign
    std::cout << s << std::endl;
    b1.executeForm(s); // execute
    b2.executeForm(s); // execute
    b3.executeForm(s); // execute
    b4.executeForm(s); // cannot execute
    b5.executeForm(s); // cannot execute

    std::cout << "\nRobotomyRequestForm test" << std::endl;
    RobotomyRequestForm r("robo");
    b1.signForm(r);
    b2.signForm(r);
    b3.signForm(r);
    b4.signForm(r); // no sign
    b5.signForm(r); // no sign
    std::cout << r << std::endl;
    b1.executeForm(r); // execute
    b2.executeForm(r); // execute
    b3.executeForm(r); // cannot execute
    b4.executeForm(r); // cannot execute
    b5.executeForm(r); // cannot execute

    std::cout << "\nPresidentialPardonForm test" << std::endl;
    PresidentialPardonForm p("bye");
    b1.signForm(p); // sign
    b2.signForm(p); // sign
    b3.signForm(p); // no sign
    b4.signForm(p); // no sign
    b5.signForm(p); // no sign
    std::cout << p << std::endl;
    b1.executeForm(p); // execute
    b2.executeForm(p); // cannot execute
    b3.executeForm(p); // cannot execute
    b4.executeForm(p); // cannot execute
    b5.executeForm(p); // cannot execute
}