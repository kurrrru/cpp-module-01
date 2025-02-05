#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl() {
    _funcs[0] = &Harl::debug;
    _funcs[1] = &Harl::info;
    _funcs[2] = &Harl::warning;
    _funcs[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() {
    std::cout << "Debug: I love having extra bacon for my "
                "7XL-double-cheese-triple-pickle-specialketchup burger. "
                "I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "Info: I cannot believe adding extra bacon costs more money. "
                "You didn’t put enough bacon in my burger! If you did, "
                "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "Warning: I think I deserve to have some extra bacon for "
                "free. I’ve been coming for years whereas you started "
                "working here since last month."<< std::endl;
}

void Harl::error() {
    std::cout << "Error: This is unacceptable! "
                "I want to speak to the manager now." << std::endl;
}

int Harl::getLevel(const std::string &level) {
    const std::string levels[4] = {"debug", "info", "warning", "error"};
    int i = 0;
    while (i != UNKNOWN && levels[i] != level) {
        i++;
    }
    return i;
}

void Harl::complain(std::string level) {
    switch (getLevel(level)) {
        case DEBUG:
            (this->*_funcs[DEBUG])();
            break;
        case INFO:
            (this->*_funcs[INFO])();
            break;
        case WARNING:
            (this->*_funcs[WARNING])();
            break;
        case ERROR:
            (this->*_funcs[ERROR])();
            break;
        default:
            std::cerr << "Unknown level: " << level << std::endl;
    }
}
