#include <iomanip>
#include <iostream>
#include <string>

int main() {
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "== Address comparison ==" << std::endl;
    std::cout << std::setw(13) << "str: " << &str << std::endl;
    std::cout << std::setw(13) << "stringPTR: " << &stringPTR << std::endl;
    std::cout << std::setw(13) << "stringREF: " << &stringREF << std::endl;

    std::cout << "== Value comparison ==" << std::endl;
    std::cout << std::setw(13) << "str: " << str << std::endl;
    std::cout << std::setw(13) << "stringPTR: " << *stringPTR << std::endl;
    std::cout << std::setw(13) << "stringREF: " << stringREF << std::endl;
}
