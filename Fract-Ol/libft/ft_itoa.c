/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:24:57 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/01 12:24:59 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	find_length(long num)
{
	int		len;

	len = 0;
	if (num == 0)
	{
		len = 1;
		return (len);
	}
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	check_zero(char str, int num)
{
	if (num == 0)
	{
		str = '0';
		return (str);
	}
	else
		return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	num;
	int		index;

	num = nb;
	index = find_length(num);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[index--] = '\0';
	str[0] = check_zero(*str, num);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[index] = '0' + (num % 10);
		num /= 10;
		index--;
	}
	return (str);
}
