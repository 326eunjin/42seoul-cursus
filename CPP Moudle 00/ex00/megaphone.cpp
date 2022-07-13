#include <iostream>
#include <cctype>
#include <cstring>

void print_in_upper_case(char *str);

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			print_in_upper_case(argv[i]);
		std::cout << std::endl;
	}
}

void print_in_upper_case(char *str)
{
	std::string tmp;
	std::string const line(str);
	for (int i = 0; i < (int)line.length(); i++)
		tmp += std::toupper(line[i]);
	std::cout << tmp;
}