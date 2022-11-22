/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:52:49 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/22 15:54:36 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	count_hex(unsigned int num)
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

static char	*hex_to_str(unsigned int num, char *base)
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

int	hex(unsigned int num, char *base)
{
	char	*str;
	int		len;

	str = hex_to_str(num, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}
