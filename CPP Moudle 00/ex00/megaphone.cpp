#include <iostream>
#include <cctype>

void	print_in_upper_case(char *str);

int main(int argc, char **argv)
{
	int i = 1;
	if(argc == 1)
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
	else
	{
		while(i < argc)
		{
			print_in_upper_case(argv[i]);
			i++;
		}
		std::cout<<std::endl;
	}
}

void	print_in_upper_case(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			toupper(str[i]);
		std::cout<<str[i];
		i++;
	}
}