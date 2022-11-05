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
	char	*destination;
	char	*source;

	source = (char *) src;
	destination = (char *) dest;
	if ((source == NULL && destination == NULL) || n == 0)
		return (destination);
	if (source < destination)
	{
		destination += n;
		source += n;
		while (n--)
		{
			*--destination = *--source;
		}
	}
	else
	{
		while (n--)
		{
			*destination++ = *source++;
		}
	}
	return ((void *) destination);
}
