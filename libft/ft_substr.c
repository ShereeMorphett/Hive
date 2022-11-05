/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:00 by smorphet          #+#    #+#             */
/*   Updated: 2022/10/25 15:03:45 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	int index;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		substr[0] = 0;
		return (substr);
	}
	substr = (char *)malloc(sizeof(char) * (len) + 1);
	if (!substr)
		return (NULL);
	index = 0;
		while ((char)s[start] && (size_t)index < len)
	{
		substr[index++] = (char)s[start++];
	}
	substr[index] = '\0';
	return	substr;
}
