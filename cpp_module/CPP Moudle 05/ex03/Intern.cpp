#include "Intern.hpp"
#include <iostream>
// ANCHOR canonical form
Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &intern) { *this = intern; }

Intern &Intern::operator=(const Intern &intern) {
    (void)intern;
    return (*this);
}

// ANCHOR makeForm()
Form *makeShubbery(std::string form_target) {
    Form *form = new ShrubberyCreationForm(form_target);
    return (form);
}

Form *makeRobotomy(std::string form_target) {
    Form *form = new RobotomyRequestForm(form_target);
    return (form);
}

Form *makePresidential(std::string form_target) {
    Form *form = new PresidentialPardonForm(form_target);
    return (form);
}

Form *Intern::makeForm(std::string form_name, std::string form_target) {
    std::string str[] = {"shrubbery", "robotomy", "presidentialpardon"};
    Form *(*funcP[3])(std::string);
    funcP[0] = makeShubbery;
    funcP[1] = makeRobotomy;
    funcP[2] = makePresidential;
    for (int i = 0; i < 3; i++) {
        if (form_name == str[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            return (funcP[i](form_target));
        }
    }
    std::cout << "Wrong form name" << std::endl;
    return (NULL);
}