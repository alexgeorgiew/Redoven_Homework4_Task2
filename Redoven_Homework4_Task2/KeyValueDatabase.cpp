#include "KeyValueDatabase.hpp"
#include <stdexcept>
#include <sstream>

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension):Object(name,location,extension)
{

}
void KeyValueDatabase:: add_entry(const std::pair<std::string, int>& entry)
{
	for (int i = 0; i < this->key.size(); i++)
	{
		if (this->key[i] == entry.first)
		{
			throw std::invalid_argument("invalid argument");
		}
	}
	this->key.push_back(entry.first);
	this->value.push_back(entry.second);
}
int KeyValueDatabase::get_value(const std::string& key) const
{
	for (int i = 0; i < this->key.size(); i++)
	{
		if (this->key[i] == key)
		{
			return this->value[i];
		}
	}
	throw std::invalid_argument("invalid argument");
}
bool KeyValueDatabase::operator==(const Comparable* input)const
{
	const KeyValueDatabase* in = dynamic_cast<const KeyValueDatabase*>(input);
	std::vector<int>checked_values;
	if (this->key.size() == in->key.size())
	{
		for (int i = 0; i < this->key.size(); i++)
		{
			bool same = false;
			for (int j = 0; j < this->key.size();j++)
			{
				if(this->key[i] == in->key[j] && this->value[i] == in->value[j])
				{
					bool is_j_in_checked_values = false;
					for (int k = 0; k < checked_values.size(); k++)
					{
						if (checked_values[k] == j)is_j_in_checked_values = true;
					}

					if (is_j_in_checked_values == true)
					{
						same = false;
					}
					else
					{
						same = true;
						checked_values.push_back(j);
						break;
					}
				}
            }
			if (same == false)return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool KeyValueDatabase::operator!=(const Comparable* input)const
{
	return !(*this == input);
}

std::string KeyValueDatabase::to_string()const
{
	std::string result = this->get_name() + '\n' + this->get_location() + '\n' + this->get_extension() + '\n';
	for (int i = 0; i < this->key.size(); i++)
	{
		result += this->key[i] + ':' + std::to_string(this->value[i]) + '\n';
	}
	return result;
}
void KeyValueDatabase::from_string(const std::string& input)
{
	std::stringstream input_as_stream(input);
	std::vector<std::string> info_as_vector;
	std::string segment;

	while (std::getline(input_as_stream, segment, '\n'))
	{
		info_as_vector.push_back(segment);
	}
	
	this->set_Name(info_as_vector[0]);
	this->set_Location(info_as_vector[1]);
	this->set_Extension(info_as_vector[2]);
	this->key.clear();
	this->value.clear();

	for (int i = 3; i < info_as_vector.size(); i++)
	{
		std::stringstream key_value(info_as_vector[i]);
		std::vector<std::string> pairs;
		while (std::getline(key_value, segment, ':'))
		{
			pairs.push_back(segment);
		}
		this->add_pair(pairs[0], std::stoi(pairs[1]));   
	}
}

std::string KeyValueDatabase::debug_print()const
{
	std::string result;
	for (int i = 0; i < this->key.size(); i++)
	{
		result += '{'+this->key[i] +':'+ std::to_string(this->value[i]) +'}'+ '\n';
	}
	return result;
}

void KeyValueDatabase::add_pair(const std::string key, const int value)
{
	for (int i = 0; i < this->key.size(); i++)
	{
		if (this->key[i] == key)
		{
			throw std::invalid_argument("invalid argument");
		}
	}
	this->key.push_back(key);
	this->value.push_back(value);
}

Object* KeyValueDatabase::clone()const
{
	return new KeyValueDatabase(*this);
}