#include "Document.hpp"
#include <stdexcept>
#include <sstream>
Document::Document(const std::string& name, const std::string& location, const std::string& extension):Object(name,location,extension)
{
	number_of_line = 1;
}
void Document::write_line(const std::string& line)
{
	this->lines.push_back(line);
}
std::string Document::read_line()
{
	if (this->number_of_line > this->lines.size())
	{
		throw std::out_of_range("out of range");
	}
	std::string result= this->lines[this->number_of_line-1];
	this->number_of_line++;
	return result;	
}
std::string Document::read_line(const unsigned line)
{
	if (line > this->lines.size())
	{
		throw std::out_of_range("out of range");
	}
		this->number_of_line = line + 1;
		return this->lines[line-1];
}
bool Document::operator==(Document* input)
{
	if (this->lines.size() == input->lines.size())
	{
		for (int j = 0; j < this->lines.size(); j++)
		{
			bool sameline = false;
			for (int i = 0; i < this->lines.size(); i++)
			{
				if (this->lines[j] == input->lines[i])
				{
					sameline = true;
					break;
				}
			}
			if (sameline == false)return false;
		}
		return true;
	}
	return false;
}
bool Document::operator!=(Document* input)
{
	return !(*this == input);
}
std::string Document::to_string()
{
	std::string result;
	result += this->get_name() + '\n' + this->get_location() + '\n' + this->get_extension() + '\n';
	for (int i = 0; i < this->lines.size(); i++)
	{
		result += this->lines[i] + '\n';
	}
	return result;
}
void Document::from_string(std::string input)
{
	std::stringstream test(input);
	std::string segment;
	std::vector<std::string> seglist;

	while (std::getline(test, segment,'\n'))
	{
		seglist.push_back(segment); 
	}

	this->set_Name(seglist[0]);
	this->set_Location(seglist[1]);
	this->set_Extension(seglist[2]);

	for (int i = 3; i < seglist.size(); i++)
	{
		this->write_line(seglist[i]);
	}
}

std::string Document::debug_print()
{
	std::string result;
	for (int i = 0; i < this->lines.size(); i++)
	{
		result +=std::to_string(i+1) + ':' + lines[i] + '\n';
	}
}