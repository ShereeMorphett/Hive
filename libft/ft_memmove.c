/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:52:21 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 16:58:48 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	source = (unsigned char *) src;
	destination = (unsigned char *) dest;
	if (source < destination)
	{
		destination += n - 1;
		source += n - 1;
		while (n--)
		{
			*destination-- = *source--;
		}
	}
	else if (source > destination)
	{
		while (n--)
		{
			*destination++ = *source++;
		}
	}
	return (dest);
}
