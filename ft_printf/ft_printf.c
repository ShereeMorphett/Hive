
#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>

int	ft_unsignedputnbr(int n)
{
	long int	storage;
    int len;

    len = 0;
	storage = n;
	if (storage < 0)
	{
		storage += 4294967295 + 1;
	}
	if (storage / 10)
	{
		len += ft_putnbr(storage / 10);
	}
	ft_putchar(storage % 10 + '0');
    len++;
	return (len);
}
static int check_conversion2(const char *arguments, va_list arg)
{
	int len;

	len = 0;
	
	if (*arguments == 'u')
	{
		len += ft_unsignedputnbr(va_arg(arg, int));
	}

	if ( *arguments == 'p')
	{	
		len += pointer(va_arg(arg, void*),  "0123456789abcdef");
	}
	if ( *arguments == 'x')
	{
		len += hex(va_arg(arg, unsigned long),  "0123456789abcdef");
	}
		if ( *arguments == 'X' )
	{
		len += hex(va_arg(arg, unsigned long),  "0123456789ABCDEF");
	}
	return (len);
}

static int check_conversion(const char *arguments, va_list arg)
{
	int len;

	len = 0;
		if ( *arguments == '%')
	{	
		len += ft_putchar('%');
	}
	if ( *arguments == 'c')
	{	
		len += ft_putchar(va_arg(arg, int));
	}
	if ( *arguments == 'i' || *arguments == 'd')
	{
		len += ft_putnbr(va_arg(arg, int));
	}
	if ( *arguments == 's')
	{
		len += ft_putstr(va_arg(arg, char *));
	}
	if	(*arguments == 'p' || *arguments == 'u' || *arguments == 'x'
		 || *arguments == 'X')
	{
		len += check_conversion2(arguments, arg);
	}
	return (len);
}

static int	pointer(void *number, char *base)
{
	int				len;
	char			*str;
	unsigned long	num;

	num = (unsigned long)number;
	str = hex_to_str(num, base);
	len = ft_putstr("0x");
	len += ft_putstr(str);
	free(str);
	return (len);
}

static int	hex(unsigned long num, char *base)
{
	char	*str;
	int		len;

	str = hex_to_str(num, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int    ft_printf(const char *arguments, ...)
{	
	    va_list arg; 
    	va_start(arg, arguments);
		int count_chars;
		
		count_chars = 0;
		while (*arguments)
		{
			if (*arguments != '%')
			{
				count_chars++;
				ft_putchar(*arguments);
				arguments++;
			}
			if (*arguments == '%')
			{
				arguments++;				
				count_chars += check_conversion(arguments, arg);
				arguments++;
			}
}
		va_end(arg);   
		return(count_chars);
}