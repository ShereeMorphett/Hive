/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:56:54 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/22 16:04:20 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int index;

	index = 0;
	if (*str == '\0')
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

int ft_putnbr(int n)
{
	long int storage;
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
