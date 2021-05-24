#include "Object.hpp"
Object::Object(const std::string& name, const std::string& location, const std::string& extension)
{
	this->name = name;
	this->location = location;
	this->extension = extension;
}
Object* Object::clone()const
{
	Object* obj;
	obj->name = this->name;
	obj->location = this->location;
	obj->extension = this->extension;
	
   return obj;
}
std::string Object::get_name() const
{
	return this->name;
}
std::string Object::get_location() const
{
	return this->location;
}
std::string Object::get_extension() const
{
	return this->extension;
}
std::string Object::get_fullpath() const
{
	std::string result = this->location + '/' + this->name + '.' + this->extension;
	return result;
}
void Object::set_Name(std::string input)
{
	this->name = input;
}
void Object::set_Location(std::string input)
{
	this->location = input;
}
void Object::set_Extension(std::string input)
{
	this->extension = input;
}