#include "PresidentialPardonForm.hpp"
#include <iostream>
// ANCHOR canonical form
PresidentialPardonForm::PresidentialPardonForm()
    : Form("Default Presidential", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("Default Presidential", 25, 5) {
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &pre)
    : Form("Default Presidential", pre.getSignGrade(), pre.getExecuteGrade()) {
    *this = pre;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &pre) {
    if (this != &pre)
        this->target = pre.getTarget();
    return (*this);
}

// ANCHOR getter
std::string PresidentialPardonForm::getTarget() const { return target; }

// ANCHOR print pardoned
void PresidentialPardonForm::printPardoned() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (getSign() == false)
        throw Form::NotSigned();
    if (getExecuteGrade() < executor.getGrade())
        throw Form::GradeTooLowException();
    printPardoned();
}