#include "Harl.hpp"

void Harl::complain(std::string level) {
    void (Harl::*funcP[4])(void);
    funcP[0] = &Harl::debug;
    funcP[1] = &Harl::info;
    funcP[2] = &Harl::warning;
    funcP[3] = &Harl::error;
    int index = (level.compare("DEBUG")) + (level.compare("INFO")) +
                (level.compare("WARNING")) + (level.compare("ERROR"));
    // std::cout << level.compare("DEBUG") << std::endl;//-25
    // std::cout << level.compare("INFO") << std::endl;//-5
    // std::cout << level.compare("WARNING") << std::endl;//51
    // std::cout << level.compare("ERROR") << std::endl;//-21
    switch (index) {
    case -25:
        (this->*funcP[0])();
    case -5:
        (this->*funcP[1])();
    case 51:
        (this->*funcP[2])();
    case -21:
        (this->*funcP[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
    }
}

void Harl::debug() {
    std::cout << "[DEBUG]" << std::endl;
    std::cout
        << "I love having extra bacon for my "
           "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
}

void Harl::info() {
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning() {
    std::cout << "[WARNING]" << std::endl;
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been "
           "coming for years whereas you started working here since last month."
        << std::endl;
}

void Harl::error() {
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}