
#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>



 void check_conversion(const char *arguments, va_list arg)
{
		if ( *arguments == '%')
	{	
		ft_putchar_fd('%', 1);
	}
	if ( *arguments == 'c')
	{	
		ft_putchar_fd(va_arg(arg, int),1);
	}
	if ( *arguments == 'i' || *arguments == 'd')
	{
		ft_putnbr_fd(va_arg(arg, int),1);
	}
	if ( *arguments == 's')
	{	
		ft_putstr_fd(va_arg(arg, char *),1);
	}

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
				ft_putchar_fd(*arguments, 1);
				arguments++;
			}
			if (*arguments == '%')
			{
				arguments++;				
				check_conversion(arguments, arg);
				arguments++;
			}
}
		va_end(arg);   
		return(count_chars);
}