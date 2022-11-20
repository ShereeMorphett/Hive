
#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

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
				count_chars += ft_putchar(*arguments, 1);
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