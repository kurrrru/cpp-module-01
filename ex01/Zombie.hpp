#pragma once

#include <iostream>
#include <string>

class Zombie {
 private:
    std::string name;

 public:
    void announce() const;
    bool setName(std::string name);
    Zombie();
    explicit Zombie(std::string name);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);
