#include "Form.hpp"
#include <iostream>

// ANCHOR canonical form
Form::Form() : name("default form"), sign_grade(150), execute_grade(150) {
    sign = false;
}

Form::Form(const std::string name, int sign_grade, int execute_grade)
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade) {
    if (sign_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &form)
    : name(getName()), sign_grade(getSignGrade()),
      execute_grade(getExecuteGrade()) {
    *this = form;
}

Form &Form::operator=(const Form &form) {
    if (this != &form)
        this->sign = form.getSign();
    return (*this);
}

// ANCHOR getter
std::string Form::getName() const { return name; }

bool Form::getSign() const { return sign; }

int Form::getSignGrade() const { return sign_grade; }

int Form::getExecuteGrade() const { return execute_grade; }

// ANCHOR setter
void Form::setSign(bool sign) { this->sign = sign; }

// ANCHOR operator <<
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "form name : " << form.getName()
        << ", form sign : " << form.getSign()
        << ", form sign grade : " << form.getSignGrade()
        << ", form execute grade : " << form.getExecuteGrade();
    return out;
}
// ANCHOR exception
const char *Form::GradeTooHighException::what(void) const throw() {
    return "Form Grade maxium is 1";
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "Form Grade minimum is 150";
}

// ANCHOR besigned()
void Form::beSigned(Bureaucrat b) {
    if (b.getGrade() <= getSignGrade())
        setSign(true);
    else
        throw Form::GradeTooLowException();
}
