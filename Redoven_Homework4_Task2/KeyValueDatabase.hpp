#pragma once
#include "Object.hpp"
#include <vector>
class KeyValueDatabase :public Object{
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    bool operator==(KeyValueDatabase* input);
    bool operator!=(KeyValueDatabase* input);

    std::string to_string();
    void from_string(std::string input);
    private:
        std::vector<std::string> key;
        std::vector<int> value;
};
