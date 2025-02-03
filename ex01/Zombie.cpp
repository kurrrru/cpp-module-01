#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(): name("default") {}

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie() {
    std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce() const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

bool Zombie::setName(std::string name) {
    this->name = name;
    return true;
}
