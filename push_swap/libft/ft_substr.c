/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:00 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/07 17:27:34 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*input_check(void)
{
	char	*substr;

	substr = malloc(sizeof(char) * 1);
	if (substr == NULL)
		return (NULL);
	substr[0] = 0;
	return (substr);
}

static int	find_size(char const *s, unsigned int start, size_t len)
{
	int	size;

	if ((ft_strlen(s) - start) < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		index;
	int		size;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (input_check());
	size = find_size(s, start, len);
	substr = (char *)malloc(sizeof(char) * (size) + 1);
	if (!substr)
		return (NULL);
	index = 0;
	while ((char)s[start] && (size_t)index < len)
	{
		substr[index++] = (char)s[start++];
	}
	substr[index] = '\0';
	return (substr);
}
