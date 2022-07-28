#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string name;
    bool sign;
    const int sign_grade;
    const int execute_grade;

  public:
    Form();
    Form(const std::string name, int sign_grade, int execute_grade);
    virtual ~Form();
    Form(const Form &form);
    Form &operator=(const Form &form);

    std::string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void setSign(bool sign);
    void beSigned(Bureaucrat b);

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

    class NotSigned : public std::exception {
      public:
        const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Form &form);
#endif