int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int	ft_putstr(char *str)
{
	int	index;
	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			index += 1;
		}
	}
    return (index);
}

int	ft_putnbr(int n)
{
	long int	storage;
    int len;

    len = 0;
	storage = n;
	if (storage < 0)
	{
		ft_putchar('-');
        len++;
		storage = -storage;
	}
	if (storage / 10)
		ft_putnbr(storage / 10);
        len++;
	ft_putchar(storage % 10 + '0');
    len++;
    return (len);
}

