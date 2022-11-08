/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:11:35 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/06 12:56:02 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	unsigned long	h_index;
	int				n_index;

	n_index = 0;
	h_index = 0;
	if (!*need)
		return ((char *)hay);
	if ((len == 0) || *hay == '\0')
		return (NULL);
	while (hay[h_index])
	{
		n_index = 0;
		while (hay[h_index] == need[n_index] && hay[h_index] && h_index < len)
		{
			h_index++;
			n_index++;
		}
		if (!need[n_index])
			return ((char *)&hay[h_index - n_index]);
		h_index = (h_index - n_index) + 1;
	}
	return (NULL);
}
