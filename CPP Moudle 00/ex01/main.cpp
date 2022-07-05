#include <iostream>
#include "Contact.hpp"
#include <string>

int main()
{
	Contact contact[8];
	std::string command;

	while(1)
	{
		if(command.compare("ADD") == 0)
			//add
		else if(command.compare("SEARCH") == 0)
			//search
		else if (command.compare("EXIT") == 0)
			//exit
		else
			std::cout<< "INVALID INPUT" << std::endl;
	}
}