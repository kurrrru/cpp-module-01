#include <iostream>
#include <fstream>
#include <string>

bool readFileToString(const char *filename, std::string *content) {
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        return false;
    }

    file.seekg(0, std::ios::end);
    std::streampos length = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[length];
    file.read(buffer, length);

    *content = std::string(buffer, length);
    delete[] buffer;
    return true;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0]
            << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if (argv[2][0] == '\0') {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string content;
    if (!readFileToString(argv[1], &content)) {
        std::cerr << "Error: could not read file " << argv[1] << std::endl;
        return 1;
    }
    std::string newContent;
    size_t pos = 0;
    size_t len = content.length();
    while (pos < len) {
        size_t next = content.find(s1, pos);
        if (next == std::string::npos) {
            newContent += content.substr(pos);
            break;
        }
        newContent += content.substr(pos, next - pos);
        newContent += s2;
        pos = next + s1.length();
    }
    std::string newFilename = std::string(argv[1]) + ".replace";
    std::ofstream file(newFilename.c_str(), std::ios::out);
    if (!file) {
        std::cerr << "Error: could not write file "
            << newFilename << std::endl;
        return 1;
    }
    file << newContent;
    file.close();
    return 0;
}