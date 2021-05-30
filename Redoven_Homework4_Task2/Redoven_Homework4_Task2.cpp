#include <iostream>
#include "KeyValueDatabase.hpp"
int main()
{
	KeyValueDatabase base("doors", ":C", ".TXT");
	base.add_entry({ "key1",1 });
	try
	{
		base.add_entry({ "key1",1 });
	}
	catch (std::invalid_argument())
	{
		std::cout << "da";
	}
	std::cout << base.to_string();


}
