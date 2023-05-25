/* 1️⃣ ft_printf.c

Allowed Functions
malloc, free, write, va_start, va_arg, va_copy and va_end
Prototype
int ft_printf(const char *, ... )
The Program
Write a function named ft_printf that will mimic the real printf but it will manage only the following conversions:

s (string)
d (decimal) 
x (lowercase hexademical)*/

 #include <stdarg.h>
 #include <unistd.h>
 //#include <stdio.h>
 //#include <limits.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_putstr(char *string)
{
	int length;

	length = 0;
	if (string == NULL)
	{
		// length = 5;
		write(1, "(null)", 6);
		return (6);
	} 
	while (*string)
	{
		ft_putchar(*string);
		string++;
		length++;
	}
	return (length);
}

int ft_putnumber(int num, int base)
{
	long int	storage;
	int count = 0;

	storage = num;
	if (storage < 0)
	{
		ft_putchar('-');
		count++;
		storage = -storage;
	}
	if (storage / base)
		count += ft_putnumber(storage / base, base);
	ft_putchar(storage % base + '0');
	count++;
	return (count);
}


int ft_puthex(unsigned num, int base)
{
	unsigned	long	storage;
	char hex_digits[] = "0123456789abcdef";
	
	int count = 0;

	storage = num;
	if (storage < 0)
	{
		ft_putchar('-');
		count++;
		storage = -storage;
	}
	if (storage / base)
		count += ft_puthex(storage / base, base);
	ft_putchar(hex_digits[storage % base]);
	count++;
	return (count);
}


int ft_printf(const char *arguments, ...)
{
	va_list	args;
	int count = 0;


	va_start(args, arguments);

	while (*arguments)
	{
		while (*arguments && *arguments != '%')
		{
			ft_putchar(*arguments);
			arguments++;
			count++;
		}
		if (*arguments == '%')
		{
			arguments++;
			if (*arguments == 's')
			{ arguments++;
				count += ft_putstr(va_arg(args, char *));
			}
			else if (*arguments == 'd')
			{ arguments++;
				count += ft_putnumber(va_arg(args, int), 10);
			}
			else if (*arguments == 'x')
			{ arguments++;
				count += ft_puthex(va_arg(args, unsigned long), 16);
			}
			else
				arguments++;
		}
	}
	return (count);
}

int main(void)
{
	int ft_ret;
	//int og_ret;

	// int nu = NULL;

	// ft_ret = ft_printf("this has nothing %s to match%d		%x	%s\n", "THINGS", nu, 'a', "\0");
	// printf("ft: %i\n", ft_ret);

	ft_ret = ft_printf("this has nothing %s \n", "\0");
//	printf("ft: %i\n", ft_ret);

//	og_ret = printf("this has nothing %s \n", "\0");
//	printf("og: %i\n", og_ret);

	// ft_printf("%x\n", INT_MIN - 1);
	// printf("%x\n", INT_MIN - 1);

	return (0);

}