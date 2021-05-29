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

    bool operator==(const Comparable* input)const;
    bool operator!=(const Comparable* input)const;

    std::string to_string()const;
    void from_string(const std::string& input);
   
    Object* clone()const override;

    std::string debug_print()const;
private:
    unsigned int number_of_line=1;
    std::vector<std::string>lines;
        
};
