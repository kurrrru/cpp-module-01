#include <string>
#include "Weapon.hpp"

Weapon::Weapon() : type("default") {}

Weapon::~Weapon() {}

Weapon::Weapon(const std::string &type) : type(type) {}

const std::string &Weapon::getType() const {
    return type;
}

bool Weapon::setType(const std::string &type) {
    this->type = type;
    return true;
}
