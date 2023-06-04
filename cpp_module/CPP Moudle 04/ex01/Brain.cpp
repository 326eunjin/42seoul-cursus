#include "Brain.hpp"
#include <iostream>
// ANCHOR Brain canonical form
Brain::Brain() {
    std::cout << "Brain Constructor is called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::~Brain() { std::cout << "Brain Destructor is called" << std::endl; }

Brain::Brain(const Brain &brain) {
    std::cout << "Brain copy constructor is called" << std::endl;
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
    std::cout << "Brain assignment operator is called" << std::endl;
    if (this != &brain) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.getIdeaStr(i);
    }
    return (*this);
}

std::string Brain::getIdeaStr(int index) const { return (ideas[index]); }

void Brain::setIdeaStr(int index, std::string tmp) { ideas[index] = tmp; }
