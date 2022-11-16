#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"
int main()
{
	int fd= open("st_test.c", O_RDONLY);
	int fd1 = open("pf_test.c", O_RDONLY);
	int empty = open("empty.txt", O_RDONLY);
	int no_nwl = open("no_nwl_test.txt", O_RDONLY);
	int moby_dick = open("moby_dick.txt", O_RDONLY);

printf("%s~~~~~~~~~~~~This will print the Next gen opening~~~~~~~~~~~~\n %s", KGRN, KWHT);
	printf("%s", get_next_line(fd));
	
printf("%s~~~~~~~~~~~~This will attempt to print an empty file~~~~~~~~~~~~\n %s", KGRN, KWHT);
	printf("%s", get_next_line(empty));
printf("%s~~~~~~~~~~~~This will attempt to print a file with no new lines~~~~~~~~~~~~\n %s", KGRN, KWHT);
	printf("%s", get_next_line(no_nwl));


printf("%s~~~~~~~~~~~~This will print the Next gen and pulp fiction files at once~~~~~~~~~~~\n %s", KGRN, KWHT);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	
	
// printf("%s~~~~~~~~~~~~This will print all of Moby Dick~~~~~~~~~~~~\n %s", KGRN, KWHT);
// 	while(get_next_line(moby_dick))
// 	{
// 		printf("%s", get_next_line(moby_dick));
// 	}
	
	
	
	
	close(fd);
	close(fd1);
	close(empty);
	close(no_nwl);
	close(moby_dick);




}