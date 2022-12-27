/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:40:13 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 17:14:04 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				index;
	const unsigned char	*store;

	index = 0;
	store = (const unsigned char *)s;
	while (index < n)
	{
		if (store[index] == (unsigned char)c)
			return ((void *)&store[index]);
		index++;
	}
	return (NULL);
}
