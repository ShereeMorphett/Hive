/* Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.*/


#include <unistd.h>

int	main(int argc, char **argv)
{
	int index = 0;

	if (argc > 1)
	{
		while(argv[1][index])
		{
			if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
				argv[1][index] = (argv[1][index] - 'a' + 13) % 26 + 'a';
			else if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
					argv[1][index] = (argv[1][index] - 'A' + 13) % 26 + 'A';
			write(1, &argv[1][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
	return (0);
}