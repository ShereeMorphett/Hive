
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUF_SIZE 4096

int main(void)
{
	int fd;
	char buf[BUF_SIZE + 1];
	int ret;
	
	fd = open("br_test_file.txt", O_RDONLY);
	if (fd == -1)
	{
			printf("open () error");
			return (1);
	}
	printf("%s", get_next_line(fd));

	fd = close(fd);
	if (fd == -1)
	{
			printf("close () error");
			return (1);
	}
	return (0);

}
