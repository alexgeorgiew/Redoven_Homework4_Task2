#include "KeyValueDatabase.hpp"
#include <stdexcept>
void KeyValueDatabase:: add_entry(const std::pair<std::string, int>& entry)
{
	for (int i = 0; i < this->key.size(); i++)
	{
		if (this->key[i] == entry.first && this->value[i] == entry.second)
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
bool KeyValueDatabase::operator==(KeyValueDatabase* input)
{
	if (this->key.size() == input->key.size())
	{
		for (int i = 0; i < this->key.size(); i++)
		{
			bool same = false;
			for (int j = 0; j < this->key.size();j++)
			{
				if(this->key[i] == input->key[i] && this->value[i] == input->value[i])
				{
					same = true;
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
bool KeyValueDatabase::operator!=(KeyValueDatabase* input)
{
	return !(*this == input);
}

std::string KeyValueDatabase::to_string()
{
	std::string result = this->get_name() + '\n' + this->get_location() + '\n' + this->get_extension() + '\n';
	for (int i = 0; i < this->key.size(); i++)
	{
		result += this->key[i] + ':' + std::to_string(this->value[i]) + '\n';
	}
	return result;
}
void KeyValueDatabase::from_string(std::string input)
{

}