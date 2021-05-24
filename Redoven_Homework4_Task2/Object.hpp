#pragma once
#include <string>
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

class Object:public Comparable,public Debug,public Serializable{
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);
    Object* clone()const;
    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;

    void set_Name(std::string input);
    void set_Location(std::string input);
    void set_Extension(std::string input);
private:
    std::string name, location, extension;
};
