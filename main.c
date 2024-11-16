#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	int fd;

	fd = open("test01.txt", O_RDONLY);

	printf("1> %s", get_next_line(fd));
	printf("2> %s", get_next_line(fd));
	printf("3> %s", get_next_line(fd));
	return (0);
}