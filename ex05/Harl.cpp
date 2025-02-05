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
	std::cout << "Debug" << std::endl;
}

void Harl::info() {
	std::cout << "Info" << std::endl;
}

void Harl::warning() {
	std::cout << "Warning" << std::endl;
}

void Harl::error() {
	std::cerr << "Error" << std::endl;
}

int Harl::getLevel(std::string level) {
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