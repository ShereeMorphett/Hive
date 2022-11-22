
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int	ft_putstr(char *str)
{
	int	index;
	index = 0;
	
	if (str == '\0')
	{
		index = ft_putstr("(null)");
	}
	if (str)
	{
		while (str[index] != '\0')
		{
			index += ft_putchar(str[index]);
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
	{
		len += ft_putnbr(storage / 10);
	}
	ft_putchar(storage % 10 + '0');
    len++;
	return (len);
}

int	count_hex(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
	    len++;
	}
	return (len);
}

char	*hex_to_str(unsigned long num, char *base)
{
	int		size;
	char	*hex;

	size = count_hex(num);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[num % 16];
		num = num / 16;
		size--;
	}
	return (hex);
}

