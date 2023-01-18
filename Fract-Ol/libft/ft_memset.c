/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:06:19 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/03 16:47:13 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*hold;
	unsigned char	change;

	change = (unsigned char) c;
	hold = str;
	while (n > 0)
	{
		*hold++ = (unsigned char) change;
		n--;
	}
	return (str);
}
