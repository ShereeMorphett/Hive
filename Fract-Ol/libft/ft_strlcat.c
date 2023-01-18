/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:44:20 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 17:04:59 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	if (size == 0)
		return (ft_strlen(src) + count);
	while (dst[index] && index < size)
		index++;
	while (src[count] && (index + count + 1) < size)
	{
		dst[index + count] = src[count];
		count++;
	}
	if (index < size)
		dst[index + count] = '\0';
	return (index + ft_strlen(src));
}
