/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:30:47 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/22 15:48:28 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_unsignedputnbr(int n)
{
	long int	storage;
	int			len;

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

static int	check_conversion2(const char *arguments, va_list arg)
{
	int	len;

	len = 0;
	if (*arguments == 'u')
	{
		len += ft_unsignedputnbr(va_arg(arg, int));
	}
	if (*arguments == 'p')
	{	
		len += pointer(va_arg(arg, void *), "0123456789abcdef");
	}
	if (*arguments == 'x')
	{
		len += hex(va_arg(arg, unsigned int), "0123456789abcdef");
	}
	if (*arguments == 'X')
	{
		len += hex(va_arg(arg, unsigned), "0123456789ABCDEF");
	}
	return (len);
}

static int	check_conversion(const char *arguments, va_list arg)
{
	int	len;

	len = 0;
	if (*arguments == '%')
	{	
		len += ft_putchar('%');
	}
	if (*arguments == 'c')
	{	
		len += ft_putchar(va_arg(arg, int));
	}
	if (*arguments == 'i' || *arguments == 'd')
	{
		len += ft_putnbr(va_arg(arg, int));
	}
	if (*arguments == 's')
	{
		len += ft_putstr(va_arg(arg, char *));
	}
	if (*arguments == 'p' || *arguments == 'u' || *arguments == 'x'
		|| *arguments == 'X')
	{
		len += check_conversion2(arguments, arg);
	}
	return (len);
}

int	ft_printf(const char *arguments, ...)
{
	va_list	arg;
	int		count_chars;

	va_start(arg, arguments);
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
	return (count_chars);
}
