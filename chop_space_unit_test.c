#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

char	*chop_space(char *str)
{
	char	*ret;
	int		front;
	int		back;
	int		i;

	i = -1;
	front = 0;
	back = ft_strlen(str) - 1;
	while (str[++i] == ' ')
		front++;
	while (str[back] == ' ')
		back--;
	ret = (char *)malloc(sizeof(char) * (back - front + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str + front, (back - front + 2));
	return (ret);
}

int main(void)
{
	char *temp;

	temp = "      hello world    ";
	printf("debug : -%s- \n", chop_space(temp));

}
