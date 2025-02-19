#include <iomanip>
#include <iostream>
#include <string>

namespace {
namespace color {
    const char light[] = "\033[1m";
    const char green[] = "\033[1;32m";
    const char red[] = "\033[1;31m";
    const char blue[] = "\033[1;34m";
    const char reset[] = "\033[0m";
}
}  // namespace

int main() {
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << color::light << "== Address comparison =="
        << color::reset << std::endl;
    std::cout << std::setw(13) << "str: " << color::green
        << &str << color::reset << std::endl;
    std::cout << std::setw(13) << "stringPTR: " << color::red
        << stringPTR << color::reset << std::endl;
    std::cout << std::setw(13) << "stringREF: " << color::blue
        << &stringREF << color::reset << std::endl;

    std::cout << color::light << "== Value comparison =="
        << color::reset << std::endl;
    std::cout << std::setw(13) << "str: " << color::green
        << str << color::reset << std::endl;
    std::cout << std::setw(13) << "stringPTR: " << color::red
        << *stringPTR << color::reset << std::endl;
    std::cout << std::setw(13) << "stringREF: " << color::blue
        << stringREF << color::reset << std::endl;
}
