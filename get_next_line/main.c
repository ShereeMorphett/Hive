
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUF_SIZE 4096

int main(void)
{
	int fd;
	int fd1;	
	fd = open("br_test_file.txt", O_RDONLY);
	if (fd == -1)
	{
			printf("open () error");
			return (1);
	}

	fd1 = open("cat_test_text.txt", O_RDONLY);
	if (fd1 == -1)
	{
			printf("open () error");
			return (1);
	}

	printf("\n%s\n", get_next_line(fd));
	//printf("\n%s", get_next_line(fd1));
	//printf("\n%s", get_next_line(fd));
	//printf("\n%s", get_next_line(fd1));
	//printf("\n%s", get_next_line(fd));
	//printf("\n%s", get_next_line(fd));

	fd = close(fd);
	if (fd == -1)
	{
			printf("close () error");
			return (1);
	}
	return (0);

}
