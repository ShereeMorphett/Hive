/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:17:29 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/31 15:17:35 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *str1_hold;
	const unsigned char *str2_hold;
	size_t	index;
	
	str1_hold = str1;
	str2_hold = str2;
	while (index < n)
	{
		if (str1_hold[index] != str2_hold[index])
		{
			return ((int)(str1_hold[index] - str2_hold[index]));
		}
		index++;
	}
	 return (0);
}