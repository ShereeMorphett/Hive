#include <unistd.h>
/* Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.*/

void	ft_putnbr(int number)
{
	char	str[10] = "0123456789";

	if (number > 9)
		ft_putnbr(number / 10);
	write (1, &str[number % 10], 1);
}

int main(void)
{	
	int count;

	count= 1;
	while (count != 100)
	{
		if (count % 3 == 0 && count % 5 == 0)
			write(1, "fizzbuzz\n", 10);
		else if (count % 3 == 0)
			write(1, "fizz\n", 5);
		else if (count % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(count);
				write(1, "\n", 1);
		}
		count++;
	}	
	return (0);
}