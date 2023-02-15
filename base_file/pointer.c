
#include <unistd.h>

static int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long int	storage;

	storage = n;
	if (storage < 0)
	{
		ft_putchar('-');
		storage = -storage;
	}
	if (storage / 10)
		ft_putnbr_fd(storage / 10, fd);
	ft_putchar(storage % 10 + '0');
}


int main(void)
{
	char *a;

	a = "stuff";
	while (*a)
	{
		ft_putchar(*a++);
		ft_putchar('\n');
	}

	return(0);
}