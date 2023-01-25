#include <unistd.h>
/* Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.*/


int main(int argc, char *argv[])
{
	int index = 0;
	int count;

	if (argc == 2)
	{
		while (argv[1][index] != '\0')
		{
			if (argv[1][index] <= 90 && argv[1][index] >= 65)
			{
				count = argv[1][index] - 64;
				while (count)
				{
					write(1, &argv[1][index], 1);
					count--;
				}
			}

			else if (argv[1][index] <= 122 && argv[1][index] >= 92)
			{
				count = argv[1][index] - 96;
				while (count)
				{
					write(1, &argv[1][index], 1);
					count--;
				}
			}

			index++;
		}

	}
	write(1, "\n", 1);
	return (0);
}