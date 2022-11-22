/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:47 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/22 15:56:36 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	pointer_count_hex(unsigned long num)
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

static char	*pointer_hex_to_str(unsigned long num, char *base)
{
	int		size;
	char	*hex;

	size = pointer_count_hex(num);
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

int	pointer(void *number, char *base)
{
	int				len;
	char			*str;
	unsigned long	num;

	num = (unsigned long)number;
	str = pointer_hex_to_str(num, base);
	len = ft_putstr("0x");
	len += ft_putstr(str);
	free(str);
	return (len);
}
