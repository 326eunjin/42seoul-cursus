#include "ShrubberyCreationForm.hpp"
#include <fstream>
// ANCHOR canonical form
ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("Default Shuberry", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("Default Shuberry", 145, 137) {
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &shrubbery)
    : Form("Default Shuberry", shrubbery.getSignGrade(),
           shrubbery.getExecuteGrade()) {
    *this = shrubbery;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shubbery) {
    if (this != &shubbery) {
        this->target = shubbery.getTarget();
        this->setSign(shubbery.getSign());
    }
    return (*this);
}

// ANCHOR getter
std::string ShrubberyCreationForm::getTarget() const { return target; }

// ANCHOR write ascii art
void ShrubberyCreationForm::writeASCII() const {
    std::string tmp = "    #####\n"
                      "   #o####\n"
                      " ######o###\n"
                      "#o#\\#|#/###\n"
                      "####\\|/#o##\n"
                      "     }|{  \n"
                      "     }|{";
    std::ofstream fout;
    fout.open(getTarget() + "_shrubbery");
    fout << tmp;
    fout.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (getSign() == false)
        throw Form::NotSigned();
    if (getExecuteGrade() < executor.getGrade())
        throw Form::GradeTooLowException();
    writeASCII();
}