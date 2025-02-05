#pragma once

#include <string>

class Harl {
 private:
	enum level {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		UNKNOWN
	};
	void (Harl::*_funcs[4])(void);
    void debug();
	void info();
	void warning();
	void error();
	int getLevel(std::string level);

 public:
	Harl();
	~Harl();
	void complain(std::string level);
};
