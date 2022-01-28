#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char *line;
	int fd;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
			printf("READ:%s", line);
			free(line);//리턴한 ret값은 여기서 이제 free해줌.
			line = NULL;
	}
	close(fd);
	system("leaks a.out");
	return 0;
}
