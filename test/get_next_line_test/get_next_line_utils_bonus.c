/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:36:32 by smorphet          #+#    #+#             */
/*   Updated: 2022/11/16 13:41:45 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(char *str, int c)
{
	int		index;
	char	find;

	find = c;
	index = ft_strlen(str);
	if (str == '\0')
		return (NULL);
	while (index >= 0)
	{
		if (str[index] == find)
			return ((char *) &str[index]);
		index--;
	}
	if (index == 0)
		return (NULL);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	index_s1;
	size_t	index_s2;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	index_s1 = -1;
	index_s2 = 0;
	if (s1)
		while (s1[++index_s1] != '\0')
			str[index_s1] = s1[index_s1];
	while (s2[index_s2] != '\0')
		str[index_s1++] = s2[index_s2++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
