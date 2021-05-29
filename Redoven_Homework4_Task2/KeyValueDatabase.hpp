#pragma once
#include "Object.hpp"
#include <vector>
class KeyValueDatabase :public Object{
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    bool operator==(const Comparable* input)const;
    bool operator!=(const Comparable* input)const;

    std::string to_string()const;
    void from_string(const std::string& input);

    Object* clone()const override;

    std::string debug_print()const;

    void add_pair(const std::string key, const int value);
    private:
        std::vector<std::string> key;
        std::vector<int> value;
};
