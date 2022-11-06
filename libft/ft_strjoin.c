/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:27:31 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/06 12:51:29 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		index;
	int		subindex;
	char	*substr;

	if (!s1)
		return (NULL);
	index = 0;
	subindex = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	substr = malloc(len + 1);
	if (substr || len == 0)
	{
		while (s1[index] != '\0')
			substr[subindex++] = s1[index++];
		index = 0;
		while (s2[index] != '\0')
		{
			substr[subindex] = s2[index++];
			subindex++;
		}
		substr[subindex] = '\0';
		return (substr);
	}
	return (NULL);
}
