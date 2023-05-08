/*Allowed Functions
read, free and malloc
Prototype
char	  *get_next_line(int fd);

The Program
LINE
Your function must return a line that has been read from the file descriptor passed as parameter.
What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n'
(ascii code 0x0a) or with End Of File (EOF).
The line should be returned including the '\n' in case there is one at the end of the line that has
been read.

BUFFER
When you've reached the EOF, you must store the current buffer in a char * and return it.

NULL
If the buffer is empty you must return NULL.
In case of error return NULL.
In case of not returning NULL, the pointer should be free-able.

MEMORY
Your program will be compiled with the flag -D BUFFER_SIZE=xx, 
which has to be used as the buffer size for the read calls in your functions.
Your function must be memory leak free.
When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the
line that has been returned.

FUNCTION
Calling your function get_next_line in a loop will therefore allow you to read the text avaiable on
a file descriptor one line at a time until the end of the text, no matter the size or either the text or one
of its lines. Make sure that your function behaves well when it reads from a file, from the standard output, from a 
edirection, etc... No call to another function will be done on the file descriptor between 2 calls of get_next_line.

FILE
Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.*/
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
#include "get_next_line.h"
int	ft_strlen(char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*get_line(char *left_str)
{
	int		index;
	char	*str;

	index = 0;
	if (!left_str[index])
		return (NULL);
	while (left_str[index] && left_str[index] != '\n')
		index++;
	str = (char *)malloc(sizeof(char) * (index + 2));
	if (!str)
		return (NULL);
	index = 0;
	while (left_str[index] && left_str[index] != '\n')
	{
		str[index] = left_str[index];
		index++;
	}
	if (left_str[index] == '\n')
	{
		str[index] = left_str[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
char	*update_left_str(char *leftover)
{
	int		index;
	int		new_ind;
	char	*new_str;

	index = 0;
	while (leftover[index] && leftover[index] != '\n')
		index++;
	if (!leftover[index])
	{
		free(leftover);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - index + 1));
	if (!new_str)
		return (NULL);
	index++;
	new_ind = 0;
	while (leftover[index])
		new_str[new_ind++] = leftover[index++];
	new_str[new_ind] = '\0';
	free(leftover);
	return (new_str);
}

char	*read_to_leftover(int fd, char *leftover)
{
	char	*buff;
	int		bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(leftover, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buff);
	}
	free(buff);
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover;

    leftover = read_to_leftover(fd, leftover);
    if (!leftover)
        return (NULL);
    line = get_line(leftover);
    leftover = update_left_str(leftover);
    return(line);
}

int main(void)
{
    int fd;

    fd = open("test.txt",  O_RDONLY);
    char *line = get_next_line(fd);

        printf("%s", line);
        line = get_next_line(fd);
   close(fd);
}