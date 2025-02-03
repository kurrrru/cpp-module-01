#pragma once

#include <string>

class Weapon {
 private:
    std::string type;

 public:
    Weapon();
    ~Weapon();
    explicit Weapon(const std::string &type);
    const std::string &getType() const;
    bool setType(const std::string &name);
};
