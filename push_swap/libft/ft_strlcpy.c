/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:53:02 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 17:00:57 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	char	*source;

	source = (char *) src;
	index = 0;
	while (source[index] && index + 1 < size)
	{
		dst[index] = source[index];
		index++;
	}
	if (size != 0)
		dst[index] = '\0';
	return (ft_strlen(src));
}
