#include "Harl.hpp"

void Harl::complain(std::string level) {
    void (Harl::*funcP[4])();

    funcP[0] = &Harl::debug;
    funcP[1] = &Harl::info;
    funcP[2] = &Harl::warning;
    funcP[3] = &Harl::error;
    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 3; i++) {
        if (level.compare(str[i]) == 0)
            return (this->*funcP[i])();
    }
    std::cout << "INVALID INPUT" << std::endl;
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