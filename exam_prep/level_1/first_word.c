#include <unistd.h>
/* Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.*/


int main (int argc, char *argv[])
{
	int index;

	index = 0;
	if (argc == 2)
	{
		while (argv[1][index] == 32 || argv[1][index] == 9)
			index++;
		while ((argv[1][index] != 32 && argv[1][index] != 9) && argv[1][index])
		{
			write(1, &argv[1][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
	return (0);
}