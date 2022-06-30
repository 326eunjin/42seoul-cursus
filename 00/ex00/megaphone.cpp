#include <iostream>

using namespace std;

void	print_in_upper_case(char *str);

int main(int argc, char **argv)
{
	int i = 1;
	if(argc == 1)
		cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< endl;
	else
	{
		while(i < argc)
		{
			print_in_upper_case(argv[i]);
			i++;
		}
	}
}

void	print_in_upper_case(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i]-=32;
		cout<<str[i];
		i++;
	}
}