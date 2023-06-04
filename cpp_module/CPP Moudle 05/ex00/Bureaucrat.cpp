#include "Bureaucrat.hpp"
#include <iostream>

// ANCHOR canonical form
Bureaucrat::Bureaucrat() : name("meme") {
    // name = "meme";
    grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) { *this = bureaucrat; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat)
        this->grade = bureaucrat.getGrade();
    // this->name = bureaucrat.getName();
    return (*this);
}

// ANCHOR getter
std::string Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

// ANCHOR setter
void Bureaucrat::setGrade(int grade) { this->grade = grade; }

// ANCHOR increment decrement
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade();
    return out;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade maxium is 1";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Grade minimum is 150";
}