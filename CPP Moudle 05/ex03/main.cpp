#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
    Bureaucrat b1("Master", 1);
    Bureaucrat b2("Gold", 10);
    Bureaucrat b3("Silver", 60);
    Bureaucrat b4("Bronze", 140);
    Bureaucrat b5("UnRanked", 150);

    std::cout << "\n";

    std::cout << "\n---------- ShrubberyCreationForm test ----------"
              << std::endl;
    ShrubberyCreationForm s("green");
    b3.executeForm(s); // cannot execute (not signed)
    b5.signForm(s);    // cannot sign (low grade)
    b4.signForm(s);    // sign
    std::cout << s << std::endl;
    b1.executeForm(s); // execute
    b2.executeForm(s); // execute
    b3.executeForm(s); // execute
    b4.executeForm(s); // cannot execute
    b5.executeForm(s); // cannot execute

    std::cout << "\n----------- RobotomyRequestForm test -----------"
              << std::endl;
    RobotomyRequestForm r("robo");
    b2.executeForm(r); // cannot execute (not signed)
    b4.signForm(r);    // cannot sign (low grade)
    b3.signForm(r);    // sign
    std::cout << r << std::endl;
    b1.executeForm(r); // execute
    b2.executeForm(r); // execute
    b3.executeForm(r); // cannot execute
    b4.executeForm(r); // cannot execute
    b5.executeForm(r); // cannot execute

    std::cout << "\n--------- PresidentialPardonForm test ----------"
              << std::endl;
    PresidentialPardonForm p("bye");
    b1.executeForm(p); // cannot execute (not signed)
    b3.signForm(p);    // cannot sign (low grade)
    b2.signForm(p);    // sign
    std::cout << p << std::endl;
    b1.executeForm(p); // execute
    b2.executeForm(p); // cannot execute
    b3.executeForm(p); // cannot execute
    b4.executeForm(p); // cannot execute
    b5.executeForm(p); // cannot execute
}