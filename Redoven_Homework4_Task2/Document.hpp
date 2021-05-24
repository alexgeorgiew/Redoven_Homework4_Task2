#pragma once
#include <string>
#include "Object.hpp"
#include <vector>

class Document:public Object {
public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);

    bool operator==(Document* input);
    bool operator!=(Document* input);

    std::string to_string();
    void from_string(std::string input);

    std::string debug_print();
private:
    unsigned int number_of_line;
    std::vector<std::string>lines;
        
};
