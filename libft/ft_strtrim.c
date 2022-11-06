/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:00:44 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/06 12:57:12 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	set_check(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	index;
	size_t	first_part;
	size_t	last_part;

	if (!s1)
		return (NULL);
	first_part = 0;
	last_part = ft_strlen(s1);
	while (s1[first_part] && set_check(s1[first_part], set))
		first_part++;
	while (last_part > first_part && set_check(s1[last_part - 1], set))
		last_part--;
	trimmed = malloc(sizeof(char) * (last_part - first_part + 1));
	if (trimmed == NULL)
		return (NULL);
	index = 0;
	while (first_part < last_part)
		trimmed[index++] = s1[first_part++];
	trimmed[index] = '\0';
	return (trimmed);
}
