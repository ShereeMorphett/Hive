
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

#define KMAG  "\x1B[35m"


int main(void)
{
	int fd;
	int fd1;	
	fd = open("st_test.txt", O_RDONLY);
	if (fd == -1)
	{
			printf("open () error");
			return (1);
	}
	fd1 = open("empty.txt", O_RDONLY);
	if (fd1 == -1)
	{
			printf("open () error");
			return (1);
	} 
	printf("\nFROM FD: %s", get_next_line(fd));
	printf("FROM FD: %s", get_next_line(fd1));
	printf("FROM FD: %s", get_next_line(fd));
	printf("FROM FD: %s", get_next_line(fd1));
	printf("\nFROM FD: %s", get_next_line(fd));
	printf("FROM FD: %s", get_next_line(fd1));
	printf("FROM FD: %s", get_next_line(fd));
	printf("FROM FD: %s", get_next_line(fd1));
	
	
	fd = close(fd);
	if (fd == -1)
	{
			printf("close () error");
			return (1);
	}
	return (0);
}
