/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:52:07 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 16:54:06 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num )
{
	size_t	index;

	index = 0;
	if (!dest && !src)
		return (0);
	while (num--)
	{
		((unsigned char *) dest)[index] = ((unsigned char *) src)[index];
		index++;
	}
	return (dest);
}
